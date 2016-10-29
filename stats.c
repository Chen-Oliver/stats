#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
  struct stat *file = (struct stat*)malloc(sizeof(struct stat));
  stat("testfile",file);
  printf("size: %lld\n",file->st_size);
  printf("permissions: %o\n",file->st_mode);
  //printf("last accessed: %d\n",file->st_atime);
  struct tm *accessed = localtime(&(file->st_atime));
  printf("%d-%d-%d\n",accessed->tm_year,accessed->tm_mon,accessed->tm_mday);
  free(file);
  return 0;
}
