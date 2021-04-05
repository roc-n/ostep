#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int rc = fork();
  pid_t parent_id=getpid();
  if (rc<0) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  }else if (rc==0) {
    pid_t wc = waitpid(parent_id, NULL,0);
    printf("child wait return:%d\n",wc);
  }else {
    pid_t wc = waitpid(-1, NULL, 0);\
    printf("parent wait return:%d\n",wc);
  }
  return 0;
}