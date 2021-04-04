#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
  int rc = fork();
  if (rc == -1) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    printf("PID of child:%d. hello!\n",getpid());
  } else {
    int wc = wait(NULL);
    printf("Parent of %d. goodbye!\n",wc);
  }
}