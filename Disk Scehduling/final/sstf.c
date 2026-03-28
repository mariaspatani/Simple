
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    printf("Enter the no of requests: ");
    scanf("%d",&n);
    int req[100];
    printf("Enter the requests: ");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    int head,visited[100]={0};
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    int pos=head,total=0;
    printf("Seek Sequence: %d ",pos);
    for(int i=0;i<n;i++){
        int min=999,index=-1;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                  int dist=abs(pos-req[j]);
                  if(dist<min){
                    min=dist;
                    index=j;
                  }
            }
        }
            visited[index]=1;
            total+=min;
            pos=req[index];
            printf("-> %d",pos);
        
    }
    printf("\nTotal head movement: %d\n",total);
    return 0;
}
