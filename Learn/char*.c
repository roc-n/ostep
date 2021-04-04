#include <stdio.h>
int main(void) {
  char *args[3];
  args[0] = "sd";
  args[1] = "qq";
  args[2] = "../..";
  printf("%s\n", args[0]);
  printf("%s\n", args[1]);
  printf("%s\n", args[2]);
  return 0;
}