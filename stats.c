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
  //struct tm *accessed = localtime(&(file->st_atime));
  printf("%s\n",asctime(localtime(&(file->st_atime))));
  free(file);
  return 0;
}
