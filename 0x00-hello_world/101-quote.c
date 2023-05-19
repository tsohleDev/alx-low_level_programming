#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
* main - Entry point
* 
* Return: Always 1 (Success)
*/

int main(void) {
    const char *message = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    write(STDERR_FILENO, message, 59);
    return 1;
}
