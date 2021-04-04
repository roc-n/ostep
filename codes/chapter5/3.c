#include <signal.h> // kill
#include <stdio.h>
#include <stdlib.h>
// #include <sys/wait.h>
#include <unistd.h>
static void sigcont_handler() { printf("goodbye!\n"); }
int main(void) {
  int parent_id = getpid();
  int rc = fork();
  struct sigaction act;
  act.sa_handler = sigcont_handler;
  if (rc == -1) {
    fprintf(stderr, "fork failed\n");
    exit(EXIT_FAILURE);
  } else if (rc == 0) {
    printf("PID of child:%d. hello!\n", getpid());
    kill(parent_id, SIGCONT);
  } else {
    // int wc = wait(NULL);
    sigaction(SIGCONT, &act, NULL);
    pause();
  }
  return 0;
}