#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void convert(int numBytes){
  int g = numBytes/1000000000;
  //numBytes%=1000;
  int m = numBytes/1000000;
  //numBytes%=1000;
  int k = numBytes/1000;
  // numBytes/=1000;
  int b = numBytes%1000;
  
  printf("%d GB %d MB %d KB %d B\n", g, m,k,b);
}

int main(){
  struct stat *file = (struct stat*)malloc(sizeof(struct stat));
  stat("a.out",file);
  convert(file->st_size);
  //printf("size: %lld\n",file->st_size);
  printf("permissions: %o\n",(file->st_mode)%512);
  printf("last accessed: %s\n",asctime(localtime(&(file->st_atime))));
  free(file);
  return 0;
}
