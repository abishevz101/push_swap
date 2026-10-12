_This project has been created as part of the 42 curriculum by vkyryche_

# Description

Libft is a custom C library created as part of the 42 school curriculum. The objective of this project is to reimplement standard C library _(libc)_ functions, as well as additional utility functions for string manipulation, dynamic memory management, file descriptor operations, and linked list processing.

# Instructions

### Functions
---

**ft_isalpha**: Checks if a character is alphabetic.

**ft_isdigit**: Checks if a character is a digit (0-9).

**ft_isalnum**: Checks if a character is alphanumeric.

**ft_isascii**: Checks if a character belongs to the ASCII character set.

**ft_isprint**: Checks if a character is printable.

**ft_strlen**: Calculates the length of a string.

**ft_memset**: Fills a block of memory with a specific byte value.

**ft_bzero**: Sets a block of memory to zero bytes.

**ft_memcpy**: Copies a memory block from source to destination.

**ft_memmove**: Copies a memory block handling overlapping memory regions safely.

**ft_strlcpy**: Copies a string to a destination buffer up to a specified size limit.

**ft_strlcat**: Appends a string to a destination buffer up to a specified size limit.

**ft_toupper**: Converts a lowercase character to uppercase.

**ft_tolower**: Converts an uppercase character to lowercase.

**ft_strchr**: Locates the first occurrence of a character in a string.

**ft_strrchr**: Locates the last occurrence of a character in a string.

**ft_strncmp**: Compares two strings up to n bytes.

**ft_memchr**: Searches memory for a specific byte.

**ft_memcmp**: Compares two memory blocks byte by byte.

**ft_strnstr**: Locates a substring in a string within a maximum search length.

**ft_atoi**: Converts an ASCII string representation of an integer to an int.

**ft_calloc**: Allocates memory for an array and initializes all bytes to zero.

**ft_strdup**: Duplicates a string by allocating dynamic memory.

**ft_substr**: Allocates and returns a substring from a given string starting at index start.

**ft_strjoin**: Allocates and returns a new string resulting from concatenating two strings.

**ft_strtrim**: Trims specified set characters from the beginning and end of a string.

**ft_split**: Splits a string into an array of strings using a delimiter character.

**ft_itoa**: Converts an integer into a null-terminated string.

**ft_strmapi**: Creates a new string by applying a function to each character of an input string.

**ft_striteri**: Applies a function to each character of a string in-place by reference.

**ft_putchar_fd**: Outputs a single character to a specified file descriptor.

**ft_putstr_fd**: Outputs a string to a specified file descriptor.

**ft_putendl_fd**: Outputs a string followed by a newline to a specified file descriptor.

**ft_putnbr_fd**: Outputs an integer to a specified file descriptor.

**ft_lstnew**: Allocates and returns a new node with content initialized.

**ft_lstadd_front**: Prepends a node to the beginning of a list.

**ft_lstsize**: Counts and returns the total number of nodes in a list.

**ft_lstlast**: Returns the final node in a list.

**ft_lstadd_back**: Appends a node to the end of a list.

**ft_lstdelone**: Frees node content using del and deletes the node.

**ft_lstclear**: Deletes and frees a given node and all its subsequent nodes.

**ft_lstiter**: Applies a function f to every node's content in a list.

**ft_lstmap**: Iterates over a list, applies f to create new contents, and builds a new list.

### Terminal Commands
---

**make**: Compile the functions

**make clean**: Remove object files (.o)

**make fclean**: Remove object files and libft.a

**make re**: Recompile from scratch

# Resources

Apart from educational purposes AI was also used for writing README file and function testing.