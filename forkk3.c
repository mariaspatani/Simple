//to create multiple child process under same parent
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  printf("Main Parent PID :%d\n\n",getpid());
 
  for(int i=0;i<3;i++){
    if(fork()==0){
      printf("CHild %d [PID :%d]->Parent [PID:%d]\n",i+1,getpid(),getppid());
      return 0;    
    }   
  }
  for(int i=0;i<3;i++){
    wait(NULL);
  }
  return 0;
}
