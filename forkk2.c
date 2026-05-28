#include<stdio.h>
#include<unistd.h>
int main(){
  int x;
  printf("Enter the value for x: ");
  scanf("%d",&x);
   pid_t pid;
   pid=fork();
   
   if(pid<0){
    printf("Fork failed!");
    return 1;
   }else if(pid==0){
    x=x+5;
    printf("Child process(x+5) : x=%d\n",x);
   }else{
    x=x-5;
    printf("Parent process (x-5):x =%d\n",x);
   }
   return 0;
}
