#include<stdio.h>
int main(){
  int n, frames;
  printf("Enter the reference length:");
  scanf("%d",&n);
  printf("Enter the no of frames:");
  scanf("%d",&frames);
  int pages[100],f[10];
  
  printf("Enter the pages: ");
  for(int i=0;i<n;i++){
    scanf("%d",&pages[i]);
  }
  for(int i=0;i<frames;i++)
        f[i] = -1;
  int fault=0;
  printf("\nPages\t");
  for(int i=0;i<frames;i++)printf("F%d\t",i+1);
  printf("Status\n");
  for(int i=0;i<n;i++){
    int found=0;
    for(int j=0;j<frames;j++){
      if(f[j]==pages[i]){
        found=1;
        break;
      }
    }
    printf("%d\t",pages[i]);
    
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
    int pos=-1,far=-1;
    for(int j=0;j<frames;j++){
      if(f[j]==-1){
        pos=j;
        break;
      }
    }
    if(pos==-1){
      for(int j=0;j<frames;j++){
        int next=-1;
        for(int k=i+1;k<n;k++){
          if(f[j]==pages[k]){
            next=k;
            break;
          }
            
        }
        if(next==-1){
          pos=j;
          break;
        }
        if(next>far){
          far=next;
          pos=j;
        }
      }
    }
      f[pos]=pages[i];
      fault++;
      
      for(int j=0;j<frames;j++){
        if(f[j]==-1){
          printf("-\t");
        }else{
          printf("%d\t",f[j]);
        }
      }
      printf("F\n");
    }
  }
  printf("Total Page Fault%d\n",fault);
  return 0;
  
}
