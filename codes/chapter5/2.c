#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(void) {
  int fd = open("two_file.txt", O_RDWR);
  int ret = fork();
  if (ret == 0) {
    printf("in child process:%d\n", fd);
  } else if (ret > 0) {
    printf("in father process:%d\n", fd);
  } else {
    fprintf(stderr, "fork failed");
    exit(1);
  }
  return 0;
}