#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("seekfile.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    if (write(fd, "ABCDEFGHIJ", 10) != 10) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    int offset = lseek(fd, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Error using lseek");
        close(fd);
        return 1;
    }
    printf("File pointer moved to position: %d\n", offset);
    if (write(fd, "1234567890", 10) != 10) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    close(fd);
    printf("File written successfully. Use `od -c seekfile.txt` to see the gaps.\n");
    return 0;
}
