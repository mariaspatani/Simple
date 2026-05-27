#include<stdio.h>
int main(){
  int n,frames;
  printf("Enter the no of reference length:");
  scanf("%d",&n);
  printf("Enter the number of frames:");
  scanf("%d",&frames);
  int pages[100],f[10],time[10];
  printf("Enter the reference pages:");
  for(int i=0;i<n;i++){
    scanf("%d",&pages[i]);
  }
  int fault=0, count=0;
  for(int i=0;i<frames;i++){
    f[i]=-1;
    time[i]=0;
  }
  printf("\nPages\t");
  for(int i=0;i<frames;i++)printf("F%d\t",i+1);
  printf("Status\n");
  for(int i=0;i<n;i++){
    int found=0;
    for(int j=0;j<frames;j++){
      if(f[j]==pages[i]){
        count++;
        time[j]=count;
        found=1;
        break;
      }
    }
    printf("%d\t",pages[i]);
    int pos=0,min=time[0];
    if(found){
      for(int j=0;j<frames;j++){
        if(f[j]==-1){
          printf("-\t");
        }else{
          printf("%d\t",f[j]);
        }
      }
      printf("H\n");
    
    }else{
      for(int j=1;j<frames;j++){
        if(time[j]<min){
          min=time[j];
          pos=j;
        }
      }
      f[pos]=pages[i];
      count++;
      time[pos]=count;
      fault++;
      
      for(int j=0;j<frames;j++){
        if(f[j]==-1)
          printf("-\t");
        else
         printf("%d\t",f[j]);
      }
       printf("F\n");
    
    
    }
  }
  printf("Total pages fault :%d\t",fault);
  return 0;
  
}
