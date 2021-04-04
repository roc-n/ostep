#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  int x = 10;
  int ret = fork();
  if (ret == 0) {
    printf("I'm child (pid:%d)\n", (int)getpid());
    printf("x in child:%d\n", x); //子进程继承来自父进程的x值
    // x = 100;
    // printf("x in child:%d\n", x);
  } else if (ret < 0) {
    fprintf(stderr, "fork failed\n");
    exit(1);
  } else {
    x = 1000;
    printf("I'm parent of %d(pid:%d) %d \n", ret, (int)getpid(), x);
    
  }

  return 0;
}