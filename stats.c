#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
  struct stat *file = (struct stat*)malloc(sizeof(struct stat));
  int s = stat("testfile",file);
  printf("size: %d\n",file->st_size);
  printf("size: %d\n",file->st_mode);
  //printf("size: %d\n",file->st_size);
  free(file);
  return 0;
}
