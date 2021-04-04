#include <signal.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int rc = fork();
  if (rc < 0) {
    fprintf(stderr, "fork failed");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    printf("child process: %d\n", getpid());
    char *myArgs[4];
    myArgs[0] = strdup("ls");
    myArgs[1] = strdup("./");
    myArgs[2] = strdup("../../");
    myArgs[3] = NULL;
    execvp(myArgs[0], myArgs);
    printf("This should't print out.\n");
  } else {
    printf("parent process: %d\n", getpid());
    int wc = wait(NULL);//不调用wait时会陷入子进程一直不返回的状态
    assert(wc>=0);
  }
  return 0;
}