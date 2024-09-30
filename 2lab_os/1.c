#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>



#define BUFFER_SIZE 4096
#ifndef DT_REG
#define DT_REG 8
#define PATH_MAX 4096
#endif

void compare_files(const char *file1, const char *file2) {
    int fd1, fd2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    ssize_t bytes_read1, bytes_read2;
    int equal = 1;
    size_t total_bytes = 0;

    fd1 = open(file1, O_RDONLY);
    fd2 = open(file2, O_RDONLY);

    if (fd1 == -1 || fd2 == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read1 = read(fd1, buffer1, BUFFER_SIZE)) > 0 &&
           (bytes_read2 = read(fd2, buffer2, BUFFER_SIZE)) > 0) {
        total_bytes += bytes_read1;
        if (bytes_read1 != bytes_read2 || memcmp(buffer1, buffer2, bytes_read1) != 0) {
            equal = 0;
            break;
        }
    }

    close(fd1);
    close(fd2);

    pid_t pid = getpid();
    printf("PID: %d, File1: %s, File2: %s, Total bytes: %zu, Result: %s\n",
           pid, file1, file2, total_bytes, equal ? "equal" : "not equal");
}


void process_directory(const char *dir1, const char *dir2, int max_processes) {
    struct dirent *entry1, *entry2;
    DIR *dp1, *dp2;
    int process_count = 0;

    dp1 = opendir(dir1);
    dp2 = opendir(dir2);

    if (dp1 == NULL || dp2 == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry1 = readdir(dp1)) != NULL) {
        if (entry1->d_type == DT_REG) {
            dp2 = opendir(dir2);
            while ((entry2 = readdir(dp2)) != NULL) {
                if (entry2->d_type == DT_REG) {
                    if (process_count >= max_processes) {
                        wait(NULL);
                        process_count--;
                    }

                    pid_t pid = fork();
                    if (pid == 0) {
                        char file1[PATH_MAX], file2[PATH_MAX];
                        snprintf(file1, PATH_MAX, "%s/%s", dir1, entry1->d_name);
                        snprintf(file2, PATH_MAX, "%s/%s", dir2, entry2->d_name);
                        compare_files(file1, file2);
                        exit(EXIT_SUCCESS);
                    } else if (pid > 0) {
                        process_count++;
                    } else {
                        perror("fork");
                        exit(EXIT_FAILURE);
                    }
                }
            }
            closedir(dp2);
        }
    }

    while (process_count > 0) {
        wait(NULL);
        process_count--;
    }

    closedir(dp1);
}

int main() {
    const char *dir1 = "Dir1";
    const char *dir2 = "Dir2";
    int max_processes = 5;

    process_directory(dir1, dir2, max_processes);

    return 0;
}