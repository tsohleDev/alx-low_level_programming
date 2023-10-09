# Hello World

Although it would get you up and going really quickly to do the _Hello World_ introduction to coding  with a language like Python and JavaScript, it is most definitely a waste of time. I really hate python btw

Hence we will go Giga Chad mode and use c/c++, more precisely we will c with the GCC compiler, in my Vim editor on my Arch Linux machine by the way but you can use your vs code on your Windows 11, 12, 15 🤮 we will wait for you while you wait for it. But make sure you install gcc

Let's create the file, Note that the extension is c because its c it would have been cpp if you followed in C++ and g++ for the compiler

```sh 
mkdir real_code
cd real_code
vim hello.c

```

To make it even better let's add a linter, Linters are an industry standard for code readability and ease of collaboration in a team, so always write code with a linter okay.

## Source Code

`hello.c`

```
#include <stdio.h>
/**
 * main - entry point
 *
 * Description - Basic Hello World program
 *
 * Return - Always 0: Success
 */

int main (void)
{
    puts ("Hello World!");
    return 0;
}
```

I know "it's very verbose", yes but also very necessary, so let's go over the constituents of our source code.

### Header files

`#include <stdio.h>`

This line consists of 3 syntactical ideas 

- **#include**: Include directive, it simply includes a "module" in the preprocessing phase of the compilation process
- **<>**: This indicates to the preprocessor that the module is a standard header file or library
- stdio.h: standard input/output header file: with the declaration of functions like `print`, and `puts` defined in the [glibc library](https://www.gnu.org/software/libc/started.html)

In conclusion `#include <stdio.h>` includes the header file `stdio.h` which is an **interface** to the _stdio_ acronym for _standard input output_ library  that allows the program to read/write input/output streams to and from the program, in our case using the `puts` function that to write on the output stream and output to your terminal A.K.A console. Although it is very important to understand how a program sends data to the output device, how it receives it from the input device, and how header files and libraries work, it might be overwhelming to include the mechanisms in this article so we will discuss them in more detail in the [Header files]() and [Input/Output devices]() piece.

### DocBlock

in any field to become better you have the be professional, The doc file is one of the essentials of well-written code, it helps with the ease of collaboration because other programmers do not need to read and try to understand the intentions of your source code, they can easily read the doc bloc arguably for you too, you could come back at your code one day and be like 'WTF', it also helps with library documentation and project documentation, therefore don't try to be smart just write your comment and doc blocks.

### The main function

The compiler uses the main function as an entry point to execution.

The main function returns a signed integer (4-byte word) with a range of $ [2]$ `0` indicates success/true and other values indicate false with each digit associated with some type of error i.e. exception


## Compilation

It might put things into perspective knowing that there are only two types of files in a computer, **text files** and **binary files**. text files are files that store text and binary files store binary, Although text files also store binary, the binary code is encoded with **asci** or **UTF-8** to make text editors easily read/write them. The binary code can be executable/program

The compilation is the process of converting source code (text file) into an executable machine code (binary file) compatible with the hardware i.e. our hello world binary file could be different based on what hardware you're compiling it for, and to drive the point home we will compile our source code for intel hardware

Now the compilation process has **four** phases or stages. with the GCC compiler, you can stop the compilation process at any of these four stages by raising a flag

### 1. Preprocessor

Here the process of moving away from text files starts by removing all the human being niceties.

- Removes **comments** since these are simply for us, not the computer
- Replace the include-directives with actual content/source code in those files
- Replaces the macros.. macros are like snippets of code that one is usually lazy to repeat a lot in the files [macros]()

```sh
    gcc -E hello.c -o clean_hello.c
```

The `-E` flag allows it to stop after preprocessing the file, and the `-o` flag allows us to name the output file in this case we will call it clean_hello.c

After running the command you should have a `clean_hello.c` file with +/- 812 lines of code filled with type definitions and extern declarations. It is code found in the standard in/output header file

### 2. Assembler

Now that your code is preprocessed, it is time to convert it to a lower lever language called assembly language 

At this point, it would be beneficial to note that so far there have been four generations of coding:

1. Machine Code at the 1st generation
2. Assembly language as the 2nd generation also know as **low level languages**
3. Modern programming languages like `[c/c++, java, go, rust, c#, ...]` A.K.A **High level languages**
4. Domain-Specific Languages and Tools like `sql`

Python is not part of any generation

Python is not real code

Python is pseudo-code

Python sucks!

```sh
    gcc -S hello.c -o hello.asm
```

Since we decided to compile for intel, the machine-specific code starts at the assembly language since each CPU has its own set of instructions

```sh
    gcc -S -masm=intel hello.c -o hello.asm'
```

The `-S` flag indicates we want to stop after generating assembly language and `masm=intel` indicates that we want intel CPU assembly instructions.
For assembly language in intel, the extension is `.asm`

Now you should have 2nd generation code in the file `hello.asm` with the following source code

```asm
        .file   "hello.c"
        .text
        .section        .rodata
.LC0:
        .string "Hello World!"
        .text
        .globl  main
        .type   main, @function
main:
.LFB0:
        .cfi_startproc
        pushq   %rbp
        .cfi_def_cfa_offset 16
        .cfi_offset 6, -16
        movq    %rsp, %rbp
        .cfi_def_cfa_register 6
        leaq    .LC0(%rip), %rax
        movq    %rax, %rdi
        call    puts@PLT
        movl    $0, %eax
        popq    %rbp
        .cfi_def_cfa 7, 8
        ret
        .cfi_endproc
.LFE0:
        .size   main, .-main
        .ident  "GCC: (GNU) 13.2.1 20230801"
        .section        .note.GNU-stack,"",@progbits
```

Now imagine debugging in that language

### 3. Compiler 

Now we take it to the 1st generation machine code

```sh
 gcc -c -masm-intel hello.c -o hello.o
```

since I am using Linux the extension is `.o` in Windows is `.exe` 

### 4. Linker

Now linking is a bit of a complicated one, but since we are already here, I might as well just shove the red pill in your mouth.

Linking which is the process done by the linker, is just the act of linking the library binaries with the source code's binaries to create the executable file.

Remember I said "The header file is an **interface** to a library", I guess there are two concepts to unpack from that phrase **interface and library**

- **Library**: A.K.A **module** is a pre-written code that one can simply plug into their code by means of an include directive in **C/C++**

    Note that every language has modules in its own way.

  **It is always a good idea to modularize your code. Benefits being: **

  1. **Fast Compilation**: Compiling a module can be exponentially faster than compiling the whole codebase
  2. **Readability** It is much easier to read a few lines and associate files with functionality
  3. **Testing** Unit tests can be made for each module, then an integration test will be simpler
 
  This would be a great time to create a library and update our hello world source file, as we will need it to proceed a little further down


  ### string.h
  
  ```c
    #ifndef _STRING_H
    #define _STRING_H
   https://github.com/tsohleDev/alx-low_level_programming/edit/main/0x00-hello_world/article.md 
    // to_upper converts a string to uppercase
    char *to_upper(char *string);
    
    // to_lower converts a string to lowercase
    char *to_lower(char *string);
    
    // copy copies a string to another string
    char *copy(char *str);
    
    #endif
  ```

  ### string.c
  ```c
    #include "string.h"
    #include <stdlib.h>
    
    /***
        * to_upper - function that capitalize first character of a word
        * @string: string to capitalize
        * Return:returns the capitalized string
        *
        * Description: This function capitalizes the first character of a word
        * in a string.
        * Example:
        *   to_upper("hello, world!") -> "HELLO, WORLD!"
    ***/
    
    
    char *to_upper(char *str) {
      int i = 0;
      for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) 
          str[i] -= 32;
      }
      return str;
    }
    
    /***
        * to_lower - function that lowercase first character of a word
        * @string: string to lowercase
        * Return:returns the lowercase string
        *
        * Description: This function lowercase the first character of a word
        * in a string.
        * Example:
        *   to_lower("HELLO, WORLD!") -> "hello, world!"
    ***/
    
    char *to_lower(char *str) {
      int i = 0;
      for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) 
          str[i] += 32;
      }
      return str;
    }
    
    /***
        * copy - function that copies a string
        * @string: string to copy
        * Return:returns the copied string
        *
        * Description: This function copies a string.
        * Example:
        *   copy("hello, world!") -> "hello, world!"
    ***/
    
    char *copy(char *str) {
      int i = 0;
      char *c = (char *)malloc(sizeof(char) * 15);
      for (i = 0; i < 15; i++) {
        c[i] = str[i];
      }
    
      return c;
    }
  ```

### hello.c
```c
#include <stdio.h>
#include "string.h"

/***
    * main - entry point
    * 
    * Return:returns 0
    *
    * Description: This function is the entry point
***/

int main() {
    char *c = to_upper(copy("hello, world!"));

    printf("%p => %s\n", c, c);

    return 0;
}
```
  
- **Interface**: A.K.A **The contract** is a file where you declare the "module", but do not implement it
    Now why would this be beneficial?

    This allows you to have a module as an object code but include it in your source code. By having the **interface** as .h and the implementation already compiled, it can still be linked together

##### In C/C++ we have two types of linking 

###### 1. Static Linking

**Static linking is just linking a library during Compile time**.

There are essentially three ways one can go about doing this

- From source file

    Generally, this is not recommended, due to its efficiency as you have to compile both files.
    
    ```sh
        gcc hello.c string.c -o hello
    ```

- From object files
    ```sh
    gcc -c string.c -o string.o # Create the binary for the library
    gcc hello.c string.o -o hello
    ```

- From archive

    Although an archive is a collection of object code files, one object code file can still be archived
    
    ```sh
    ar rcs libstring.a string.o
    gcc hello.c -o hello -lstring
    ```


###### 1. Dynamic Linking

```sh
gcc -fPIC -shared string.c -o libstring.so # create the shared object
gcc hello.c -o hello -lstring
```


And that's it, folks. One of the most helpful Hello World tutorials you can ever do to become a real developer. You can apply for that senior position now, in fact, you can even apply to be the CEO, in fact, forget to apply, you are now the CEO, in fact, screw the CEO, you are now the president. Thank you, Madam President, this way Madam President. "The nest has secured the egg, I repeat the nest has secured the egg"


