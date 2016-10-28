#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(){
  struct stat *file = (struct stat*)malloc(sizeof(struct stat));
  stat("testfile",file);
  printf("size: %lld\n",file->st_size);
  printf("permissions: %o\n",file->st_mode);
  printf("last accessed: %d\n",file->st_atimespec);
  free(file);
  return 0;
}
