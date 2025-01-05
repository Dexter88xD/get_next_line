# Get Next Line

get_next_line is a C library that provides a convenient function to read lines from a file descriptor. It is especially useful for processing text files line-by-line in a memory-efficient manner.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [File Sturcture](#file_structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction
get_next_line is a C function that enables reading a file line-by-line, simplifying text processing tasks. This project is part of the 42 coding school curriculum, focusing on efficient memory and file descriptor management.

## Features

- Reads one line at a time from a file descriptor.
- Handles multiple file descriptors in the bonus version.
- Works with files of any size, including large files.

## File Structure

The repository is organised into the following files:

- Core Files:
    - get_next_line.c – Implementation of the get_next_line function.
    - get_next_line.h – Header file containing function prototypes and macros.
    - get_next_line_utils.c – Utility functions supporting get_next_line.

- Bonus Files:
    - get_next_line_bonus.c – Implementation of get_next_line for multiple file descriptors.
    - get_next_line_bonus.h – Header file for the bonus version.
    - get_next_line_utils_bonus.c – Utility functions supporting the bonus version.

## Installation

To integrate get_next_line into your project:

- Copy the required source (.c) and header (.h) files into your project directory.
-Include the appropriate header file in your code:
```c
    #include "get_next_line.h"       // For single file descriptor use.
    #include "get_next_line_bonus.h" // For multi file descriptor support (bonus version).
```

## Usage

Below is an example demonstrating the use of get_next_line:
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Don't forget to free the allocated memory!
    }

    close(fd);
    return (0);
}
```
For the bonus version, you can handle multiple file descriptors simultaneously using the same approach.
Dependencies

The library relies on standard C libraries, so no external dependencies are required:
```
    <fcntl.h>
    <stdio.h>
    <stdlib.h>
    <string.h>
    <unistd.h>
```
## Contributing

Contributions are welcome! Feel free to:
- Open an issue for bug reports or feature requests.
- Submit a pull request with your enhancements or fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
Contributing
