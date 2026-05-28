#include<stdio.h>
#include<unistd.h>
#include<sys/wait>
#inlucde<sys/type.h>
int main(){
  pid_t pid;
  pid=fork();
  if(pid==0){
    printf("24CS165 ");
  }
  else{
    wait(NULL);
    printf("Os Lab");
  }
  return 0;
}
