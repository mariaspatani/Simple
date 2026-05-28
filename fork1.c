#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("fork failed");
		return 1;
	}else if(pid==0){
		printf("Child Process:\n");
		printf("Child Pid:%d\n",getpid());
		printf("parent pid:%d\n",getppid());
	}else{
		printf("parent process:\n");
		printf("child pid:%d\n",pid);
		printf("parent pid:%d\n",getpid());
	}
	sleep(300);
	return 0;
}

