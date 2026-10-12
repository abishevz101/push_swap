*This project has been created as part of the 42 curriculum by vkyryche, zabishev.*

# push_swap

Sort a list of integers on two stacks with a very small instruction set, using as few operations as possible, with a program that chooses its sorting strategy at runtime from the measured disorder of the input.

## Table of Contents

1. [Description](#description)
2. [Instructions](#instructions)
3. [Algorithms and Justification](#algorithms-and-justification)
4. [Performance Results](#performance-results)
5. [Testing](#testing)
6. [Project Structure](#project-structure)
7. [Team Contributions](#team-contributions)
8. [Resources](#resources)

---

## Description

`push_swap` is an algorithmic project of the 42 curriculum. The program receives a list of distinct 32-bit integers, which becomes **stack `a`** (the first argument is the top). **Stack `b`** starts empty. The program prints, one per line on `stdout`, a list of operations that leaves `a` sorted in ascending order (smallest on top) and `b` empty.

The 11 allowed operations:

| Operation | Effect |
| :-- | :-- |
| `sa` / `sb` / `ss` | Swap the top two elements of `a` / `b` / both |
| `pa` / `pb` | Push the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | Rotate `a` / `b` / both up (first element becomes last) |
| `rra` / `rrb` / `rrr` | Reverse rotate `a` / `b` / both down (last element becomes first) |

The goal is to experience **algorithmic complexity** concretely. Complexity is measured in the number of push_swap operations produced, not in CPU time of a classical array algorithm.

**Overview of what the program does**

- Computes a **disorder metric** (0 = sorted, 1 = fully reversed) *before* making any move.
- Embeds **four strategies**: Simple `O(n²)`, Medium `O(n√n)`, Complex `O(n log n)` and a custom **Adaptive** strategy that picks one of the three from the disorder.
- Lets the user force a strategy with `--simple`, `--medium`, `--complex` or `--adaptive` (default).
- Offers a `--bench` mode that prints disorder, strategy, complexity class and operation counts on `stderr`, without touching the operation stream on `stdout`.

---

## Instructions

### Compilation

The `Makefile` uses `cc -Wall -Wextra -Werror`, builds the bundled `libft/` through its own Makefile, and does not relink if nothing changed.

```bash
make        # build ./push_swap (and libft/libft.a)
make clean  # remove object files
make fclean # remove object files and binaries (including libft.a)
make re     # fclean + all
```

### Usage

```bash
./push_swap [strategy] [--bench] <integers...>
```

| Flag | Meaning |
| :-- | :-- |
| `--simple` | Force the `O(n²)` strategy (min extraction, hard-coded sorts for n ≤ 5) |
| `--medium` | Force the `O(n√n)` strategy (chunk sort) |
| `--complex` | Force the `O(n log n)` strategy (binary LSD radix sort) |
| `--adaptive` | Choose the strategy from the disorder (**default**) |
| `--bench` | Print benchmark information on `stderr` |

Only one strategy flag may be given; flags and numbers can be mixed in any order. Numbers can be separate arguments or quoted in one string (`"4 67 3 87 23"`).

### Behaviour

- No arguments: prints nothing and returns.
- Invalid input (non-integer, out of `int` range, duplicate, empty string, two strategy flags, unknown flag): prints `Error` followed by `\n` on `stderr`, exit status 1.
- Already sorted input (including a single number): prints nothing.

### Examples

```bash
$ ./push_swap 2 1 3 6 5 8
$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | wc -l
$ ./push_swap --simple 5 4 3 2 1
$ ./push_swap --adaptive 0 one 2 3
Error
$ ./push_swap --simple 3 2 3
Error
```

Benchmark mode (operations go to `stdout`, the report goes to `stderr`):

```bash
$ ./push_swap --bench 4 67 3 87 23 2>&1 >/dev/null
Disorder: 40.00%
Strategy: Adaptive / O(n^2)
Total operations: 9
sa: 0 sb: 0 ss: 0 pa: 2 pb: 2
ra: 4 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

---

## Algorithms and Justification

### Common notation

`n` is the number of elements. Complexities are **upper bounds on the number of push_swap operations printed**. Work done by the program itself without printing an operation (computing the disorder, computing ranks) is not counted as operations but is listed under "extra space/CPU" for completeness.

### Disorder metric

Before any move, the program counts all pairs `(i, j)` with `i < j` and the "mistakes" among them (`a[i] > a[j]`):

```
disorder = mistakes / total_pairs        (0.0 sorted … 1.0 reversed)
```

It costs `O(n²)` CPU, `O(1)` memory and **zero operations**. If the disorder is exactly 0, the program stops immediately and prints nothing. A uniformly random permutation has an expected disorder of 0.5, because each pair is inverted with probability ½.

### Rank normalisation

The Medium and Complex strategies first replace every value by its **rank** (the number of smaller values, so the stack becomes a permutation of `0 … n-1`). This lets the algorithms work on small, dense integers whatever the original values (negative numbers, huge gaps) and makes bit extraction and chunk boundaries trivial. Ranks are computed in `O(n²)` CPU (no operations) and stored in a temporary `O(n)` array that is freed right after.

### 1. Simple strategy: `O(n²)` (`--simple`)

**Technique:** selection sort adapted to the two stacks (min extraction), with hard-coded sequences for tiny stacks.

1. Find the smallest element of `a`.
2. Rotate `a` the shortest way (`ra` if it is in the upper half, `rra` otherwise) until it is on top, then `pb`.
3. Repeat until one element is left in `a`, then `pa` everything back. Since the minima were pushed in ascending order, they come back in ascending order.

**Small stacks (n ≤ 5)** are handled by dedicated code in `sort_for_three.c`:

- n = 2: `sa` if needed.
- n = 3: `sort_three` compares the three values and applies at most 2 operations from `sa`, `ra`, `rra`.
- n = 4 and 5: push the 1 (or 2) smallest elements to `b` via the shortest rotation, `sort_three` the rest, `pa` back.

Measured on **all** permutations: at most 2 operations for n = 3, 6 for n = 4, 10 for n = 5.

**Complexity argument.** For `n > 5`, step *k* costs at most `⌊(n−k)/2⌋` rotations plus one `pb`, and the last phase costs `n−1` `pa`. Total ≤ `n²/4 + 2n` = **O(n²)** operations. Extra space: `O(1)` (the elements only move between the two stacks).

**Why we keep it:** it is the simplest, it is optimal-ish for tiny inputs, and for very low disorder its operation count is smaller than the more complex methods (see the results below).

### 2. Medium strategy: `O(n√n)` (`--medium`)

**Technique:** chunk (range-based) partitioning with `⌊√n⌋` chunks, then insertion back.

1. Convert values to ranks. Let `k = ⌊√n⌋` and `chunk_size = ⌈n/k⌉`. Chunk *c* holds ranks `[c·chunk_size, (c+1)·chunk_size − 1]`.
2. For chunks `0 … k−2`: repeatedly find the first element of `a` (from the top) that belongs to the current chunk, rotate it to the top by the shorter direction, and `pb`. After this phase `b` holds the low chunks and `a` keeps roughly one chunk (about √n elements, the highest ranks).
3. Sort the small remainder in `a` with a bubble sort made of `sa` / `ra` (about √n elements, so `O(√n²) = O(n)` operations).
4. While `b` is not empty: find where the top of `b` belongs in `a` (position of its next larger value), rotate `a` there by the shorter direction and `pa`.
5. Rotate the minimum to the top.

**Complexity argument.**

- Step 2: each chunk is collected with roughly one sweep through `a`, i.e. `O(n)` rotations plus `√n` pushes. There are `√n − 1` chunks → `O(n√n)`.
- Step 3: `O(n)`.
- Step 4: elements leave `b` chunk by chunk, so the insertion point in `a` is always inside, or next to, the sorted run formed by the current chunk. Each insertion therefore costs `O(√n)` rotations. For `n` elements → `O(n√n)`.
- Total: **O(n√n)** operations. Extra space `O(1)` (besides the temporary ranks).

### 3. Complex strategy: `O(n log n)` (`--complex`)

**Technique:** binary **LSD radix sort** on ranks.

With ranks in `0 … n−1`, `bits = ⌈log₂ n⌉` passes are needed. In pass `i`, the program looks at each of the `n` elements once:

- bit `i` of the rank is `1` → `ra` (keep in `a`, send to the bottom);
- bit `i` is `0` → `pb`.

Then all of `b` is pushed back with `pa`. Because each pass is stable, after the last bit the stack is sorted.

**Complexity argument.** One pass costs `n` operations (`ra` or `pb`) plus at most `n` `pa` → ≤ `2n`. With `⌈log₂ n⌉` passes the total is ≤ `2n⌈log₂ n⌉` = **O(n log n)**. Extra space `O(1)` (besides the temporary ranks). Note that the operation count only depends on `n` and on how many ranks have a 0 bit, which is fixed for a permutation of `0 … n−1`: it is **the same for every input of the same size** (1084 operations for n = 100, 6784 for n = 500).

### 4. Adaptive strategy (`--adaptive`, default)

The adaptive strategy is a dispatcher on the disorder computed at the start:

| Condition | Strategy used | Class |
| :-- | :-- | :-- |
| disorder = 0 | nothing to do | 0 operations |
| `n ≤ 5` **or** disorder < 0.2 | Simple (hard-coded for n ≤ 5, min extraction otherwise) | `O(n²)` |
| 0.2 ≤ disorder < 0.5 | Medium (chunk sort) | `O(n√n)` |
| disorder ≥ 0.5 | Complex (radix sort) | `O(n log n)` |

**Rationale for the thresholds.** The 0.2 / 0.5 boundaries and the complexity target of each regime come from the subject. We validated them with measurements on n = 500 inputs built by applying random swaps to a sorted list (operation counts, lower is better):

| Disorder | Simple | Medium | Complex |
| :-- | --: | --: | --: |
| 1.4 % | 1816 | 1772 | 6784 |
| 7.1 % | 5768 | 4168 | 6784 |
| 14.1 % | 10074 | 5222 | 6784 |
| 22.2 % | 17408 | 6775 | 6784 |
| 34.8 % | 27009 | 7600 | 6784 |
| 45.0 % | 31545 | 7870 | 6784 |
| 51.4 % | 31505 | 8502 | 6784 |

What this shows: the Complex strategy has a flat cost, so it is the safe choice for high disorder; Medium wins as soon as the input is not almost random; Simple is only competitive at very low disorder, and for n ≤ 5 it is simply the cheapest option, which is why small stacks always use it. On our implementation Medium and Complex cross at roughly 22 % disorder, so a threshold lower than 0.5 would give fewer operations for the high-disorder regime. We kept the subject's thresholds so that the three regimes map exactly onto the three required classes.

**Complexity of the adaptive strategy.** It runs exactly one of the three strategies above after an operation-free `O(n²)` CPU disorder computation, so its cost is the cost of the selected regime: `O(n²)`, `O(n√n)` or `O(n log n)` operations respectively. Extra space is `O(1)` besides the temporary `O(n)` rank array.

---

## Performance Results

Measured with a Python re-implementation of the 11 operations used as checker (all outputs verified: stack `a` sorted, `b` empty). 30 random permutations per row.

| Size | Strategy | min | average | max |
| :-- | :-- | --: | --: | --: |
| 3 | adaptive | 0 | 0 | 2 |
| 5 | adaptive | 5 | 7 | 10 |
| 100 | `--medium` | 802 | 868 | 914 |
| 100 | `--complex` | 1084 | 1084 | 1084 |
| 100 | adaptive | 825 | 1001 | 1084 |
| 500 | `--medium` | 8066 | 8351 | 8528 |
| 500 | `--complex` | 6784 | 6784 | 6784 |
| 500 | adaptive | 6784 | 7542 | 8421 |

Subject thresholds: 100 numbers: < 2000 pass, < 1500 good, < 700 excellent. 500 numbers: < 12000 pass, < 8000 good, < 5500 excellent. Our results pass both, and are in the "good" range on average. A random input has disorder around 0.5, so the adaptive strategy alternates between Medium and Complex on random data.

---

## Testing

```bash
# errors (stderr: Error)
./push_swap 1 2 two ; ./push_swap 1 2 2 ; ./push_swap 2147483648 ; ./push_swap "" ; ./push_swap --simple --medium 3 2 1
# nothing printed
./push_swap ; ./push_swap 42 ; ./push_swap 1 2 3 4 5

# correctness + operation count on random input
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l

# every strategy on the same input
for f in --simple --medium --complex --adaptive; do ./push_swap $f $ARG | wc -l; done

# benchmark on stderr only
./push_swap --bench $ARG 2> bench.txt

# leaks / invalid accesses
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1 4 5 7 6 9 8
```

All permutations of 2 to 5 elements were checked exhaustively with every strategy flag (all sorted correctly).

---

## Project Structure

| File | Content |
| :-- | :-- |
| `main.c` | Entry point, disorder metric, strategy dispatch (`run_algorithm`) |
| `parsing.c` | Argument and flag parsing, validation, duplicates, range check |
| `stack_management.c` | Linked-list stack: add, free, size |
| `the_rules_s.c`, `the_rules_rr.c`, `the_rules_rrr.c` | The 11 operations (print + counters) |
| `s_algorithm.c`, `sort_for_three.c` | Simple strategy and small-stack sorts |
| `m_algorithm.c`, `m_algorithm_help.c` | Medium strategy (chunk sort) and helpers |
| `c_algorithm.c` | Rank normalisation and Complex strategy (radix sort) |
| `bench.c` | `--bench` report |
| `push_swap.h` | Structures and prototypes |
| `libft/` | Our libft (built by the Makefile) |

The stacks are singly linked lists. Operations take a `rule` flag so that combined operations (`ss`, `rr`, `rrr`) can reuse the single-stack versions without printing twice, and a `t_bench` pointer so every operation updates its counter.

---

## Team Contributions

| Learner | Contribution |
| :-- | :-- |
| **vkyryche** | Argument parsing and validation (`parsing.c`), stack management (`stack_management.c`), benchmark mode (`bench.c`), `main.c`, `Makefile` |
| **zabishev** | All sorting algorithms (`s_algorithm.c`, `sort_for_three.c`, `m_algorithm.c`, `m_algorithm_help.c`, `c_algorithm.c`) and the 11 operations (`the_rules_*.c`) |
| **Both** | `push_swap.h`, the adaptive thresholds and strategy dispatch, `libft` integration, testing and this README |

Both learners can explain every part of the code.

---

## Resources

**References**

- 42 subject: *push_swap*, version 1.1.
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Sorting algorithm overview](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [The Norm](https://meta.intra.42.fr/articles/the-norm-v4)

**AI usage**

AI tools were used for the following tasks only:

- Discussing algorithmic options and their complexity in the push_swap operation model, and optimisation ideas for the strategies.
- Debugging and brainstorming edge cases for the parser and the strategy dispatch.
- Structuring and writing this README. The AI was also used to run measurements (operation counts, exhaustive tests of small permutations) with a throwaway checker script that is not part of the repository; the numbers above come from those runs.
