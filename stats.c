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

void convertPermissions(int per){
  int power = 256;
  while(power){
    if(per/power){
      if((power==4)||(power==32)||(power==256)){
	printf("r");
      }else if((power==2)||(power==16)||(power==128)){
	printf("w");
      }else{
	printf("x");
      }
    }else{
      printf("-");
    }
    per%=power;
    power/=2;
  }
  printf("\n");
}
int main(){
  struct stat *file = (struct stat*)malloc(sizeof(struct stat));
  stat("a.out",file);
  convert(file->st_size);
  //printf("size: %lld\n",file->st_size);
  //printf("permissions: %o\n",(file->st_mode)%512);
  convertPermissions((file->st_mode)%512);
  printf("last accessed: %s\n",asctime(localtime(&(file->st_atime))));
  free(file);
  return 0;
}
