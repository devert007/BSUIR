#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void print_process_info(__pid_t pid, __pid_t ppid) {
    printf("Process ID: %d, Parent Process ID: %d\n", pid, ppid);
}





int main(){
 __pid_t pid;
  pid=fork();
  int fork_tree[] = {0, 1, 1, 2, 2, 5, 6};
    int exec_process = 3;
for (int i = 0; i < sizeof(fork_tree) / sizeof(fork_tree[0]); i++) {
        __pid_t pid = fork();

     if (pid > 0) {
            // Parent process
            print_process_info(getpid(), getppid());
            printf("Process %d spawned process %d\n", getpid(), pid);
        } else {
           print_process_info(getpid(), getppid());

            if (i == exec_process) {
             //   execlp("/file","pwd",NULL);
            }

            break;
        }
  }
  // for (int i = 0; i < sizeof(fork_tree) / sizeof(fork_tree[0]) - 1; i++) {
  //       wait(NULL);
  //   }

  //   printf("Process %d (Parent: %d) is terminating\n", getpid(), getppid());

}