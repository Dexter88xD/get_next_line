# Get Next Line

`get_next_line` is a C library that provides a convenient function to read lines from a file descriptor. It is especially useful for processing text files line-by-line in a memory-efficient manner.

---

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [File Sturcture](#file-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

`get_next_line` is a standalone C function designed to read files line by line in a memory-efficient manner. It simplifies text processing by dynamically managing memory and file descriptors, making it capable of handling files of any size. This project, part of the 42 coding school curriculum, emphasises efficient memory usage and practical file handling techniques.

---

## Features

- Reads one line at a time from a file descriptor.
- Handles multiple file descriptors in the bonus version.
- Works with files of any size, including large files.
- Adheres to the 42 coding school’s strict coding standards.

---

## File Structure

The repository is organised into the following files:

- Core Files:
    - `get_next_line.c` – Implementation of the get_next_line function.
    - `get_next_line.h` – Header file containing function prototypes and macros.
    - `get_next_line_utils.c` – Utility functions supporting get_next_line.

- Bonus Files:
    - `get_next_line_bonus.c` – Implementation of get_next_line for multiple file descriptors.
    - `get_next_line_bonus.h` – Header file for the bonus version.
    - `get_next_line_utils_bonus.c` – Utility functions supporting the bonus version.

---

### **Installation**

To integrate `get_next_line` into your project, follow these steps:

1. **Clone the Repository**  
   Clone the `get_next_line` repository:  
   ```bash
   git clone https://github.com/Dexter88xD/get_next_line.git
   ```

2. **Navigate to the Repository**  
   Move into the cloned directory:  
   ```bash
   cd get_next_line
   ```

3. **Copy the Files**  
   Transfer the required files to your project directory:  
   ```bash
   cp get_next_line.c get_next_line_utils.c get_next_line.h ../your_project/
   ```

4. **Update Your Code**  
   Include the appropriate header file(s) in your source code:  
   ```c
   #include "get_next_line.h"       // For single file descriptor usage.
   #include "get_next_line_bonus.h" // For multi-descriptor support (bonus version).
   ```

5. **Compile Your Program**  
   Combine `get_next_line` with your project during compilation:  
   ```bash
   gcc -Wall -Wextra -Werror your_program.c get_next_line.c get_next_line_utils.c -o your_program
   ```

---

### **Usage**

Here’s an example to demonstrate the use of `get_next_line`:

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
        free(line); // Free allocated memory for each line.
    }

    close(fd);
    return (0);
}
```

For the **bonus version**, use the same approach to handle multiple file descriptors simultaneously.  

---

### **Dependencies**  

`get_next_line` requires standard C libraries for functionality and does not depend on external packages:  
```c
<fcntl.h>
<stdio.h>
<stdlib.h>
<string.h>
<unistd.h>
```  

---

## Contributing

Contributions are welcome! Feel free to:
- Open an issue for bug reports or feature requests.
- Submit a pull request with your enhancements or fixes.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.
