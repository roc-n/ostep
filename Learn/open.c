#include <fcntl.h>  //open()
#include <stdio.h>  //perror()
#include <stdlib.h> //exit()
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h> //close()

int main(void) {
  int fd1; //文件描述符:一个整形数组(0~1023),0~2为系统默认打开的文件
  int res;

#ifdef HELLO
  //打开一个不存在的文件
  fd1 = open(
      "hello",
      O_RDWR); //返回对应的文件描述符，第一个参数是文件路径及名称，第二个参数为操作方式,O_RDWR为读操作
  if (fd1 == -1) //-1 表示失败
  {
    perror("open file hello"); // perror打印错误信息,系统的errno代表的文字信息
    exit(1);
  } else {
    printf("open hello fd1 = %d\n", fd1);

    //关闭文件
    res = close(fd1); //传递要关闭的文件的文件描述符
    printf("close fd1 res = %d\n", res); //返回0关闭成功，-1失败
    if (res == -1) {
      perror("close fd1");
      exit(1);
    }
  }
#endif

  //打开一个已经存在的文件
  int fd2 = open("hello_open.c", O_RDWR);
  if (fd2 == -1) {
    perror("open file hello_open.c");
    exit(1);
  } else {
    printf("hello_open.c fd2 = %d\n", fd2);
    res = close(fd2);
    printf("close fd2 res = %d\n", res);
    if (res == -1) {
      perror("close fd2");
      exit(1);
    }
  }

  //创建新文件:O_CREAT
  int fd3 = open("CreateFile", O_CREAT | O_RDWR, 0777);
  if (fd3 == -1) {
    perror("create file");
    exit(1);
  } else {
    printf("CreatFile fd3 = %d\n", fd3);
    res = close(fd3);
    printf("close fd3 res = %d\n", res);
    if (res == -1) {
      perror("close fd3");
      exit(1);
    }
  }

//#define EXCL
#ifdef EXCL
  //判断文件是否存在:O_EXCL
  int fd4 = open("CreateFile", O_CREAT | O_EXCL | O_RDWR, 0777);
  if (fd4 == -1) { //文件已经存在，创建失败
    perror("create and testEXCL file");
    exit(1);
  } else {
    printf("EXCLtest fd4 = %d\n", fd4);
    res = close(fd4);
    printf("close fd4 res = %d\n", res);
    if (res == -1) {
      perror("close fd4");
      exit(1);
    }
  }
#endif

#define TRUNC
#ifdef TRUNC
  //将文件截断为0
  int fd5 = open("hello_open.c", O_RDWR | O_TRUNC);
  if (fd5 == -1) {
    perror("trunc file");
    exit(1);
  } else {
    printf("trunc fd5 = %d\n", fd5);
    res = close(fd5);
    printf("close fd5 res = %d\n", res);
    if (res == -1) {
      perror("close fd5");
      exit(1);
    }
  }
#endif

  return 0;
}
