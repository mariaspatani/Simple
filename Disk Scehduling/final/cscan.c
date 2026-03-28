
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, disk_size;
    printf("Enter the disk_size: ");
    scanf("%d",&disk_size);

    printf("Enter the no of requests: ");
    scanf("%d",&n);

    int req[100];
    printf("Enter the requests: ");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }
    //bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(req[j]>req[j+1]){
                int t=req[j];
                req[j]=req[j+1];
                req[j+1]=t;
            }
        }
    }
     int head,total=0;
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    //split
    int split=0;
    for(int i=0;i<n;i++){
        if(req[i]>head){
            split=i;
            break;
        }
    }
    
    
    int pos=head;
    printf("Seek Sequence: %d ",pos);
    //right split
    for(int i=split;i<n;i++){
        total+=abs(pos-req[i]);
        pos=req[i];
         printf("-> %d",pos);
    }
    //jump to 0
    total+=abs(pos-disk_size+1);
    pos=disk_size-1;
    printf("-> %d",pos);

    total+=abs(pos-0);
    pos=0;
     printf("-> %d",pos);
//left side
    for(int i=0;i<split;i++){
        total+=abs(pos-req[i]);
        pos=req[i];
        printf("-> %d",pos);
    }
    printf("\nTotal head movement: %d\n",total);
    return 0;
}
