#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }
    char *file_Name = argv[1];

    int writeFd;

    fprintf(stdout, "Opening file :%s\n", file_Name);
    writeFd = open(file_Name, O_RDWR, O_NONBLOCK, O_APPEND);

    if (writeFd < 0) {
        printf("Error with file open\n");
        exit(-1);
    }

    fprintf(stdout, "Seeking the beginning of the file \n");

    if (lseek(writeFd, 0, SEEK_SET) >= 0) {
        fprintf(stdout, "Writing the message into %s\n", file_Name);
        char buffer[BUF_SIZE] = "Message from Exercise 3\n";
        write(writeFd, buffer, BUF_SIZE);
        close(writeFd);

        return 0;
    }
}