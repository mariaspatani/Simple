//ptrace
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ptrace.h>
int main(){
  pid_t pid;
  pid=fork();
  if(pid<0){
    printf("Fork failed \n");
    return 1;
  }else if( pid==0){
      
      ptrace(PTRACE_TRACEME,0,NULL,NULL);
      printf("Child Process: \n");
      printf("\nChild Process %d ",getpid());
      printf("\nparent process %d",getppid());  
  }else{
    wait(NULL);
    printf("\nparent process \n");
    printf("\nparent process %d",getpid()); 
    printf("\nchild process %d" ,pid);
    printf("\nParent is tracing child using ptrace\n");
    
  }
  return 0;
}
