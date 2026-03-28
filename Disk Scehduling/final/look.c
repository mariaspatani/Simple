#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, head;
    
    printf("Enter number of requests: ");
    scanf("%d",&n);
    int req[100];
    
    printf("Enter requests:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);
        
    printf("Enter initial head: ");
    scanf("%d",&head);
    
    // BUBBLE SORT entire array
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(req[j] > req[j+1]){
                int temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }
        }
    }
    
    // Find split point
    int split = 0;
    for(int i=0; i<n; i++){
        if(req[i] >= head){
            split = i;
            break;
        }
    }
    
    int pos = head, total = 0;
    printf("\nSeek Sequence: %d",pos);
    
    // 1. Right side first
    for(int i=split; i<n; i++){
        total += abs(pos - req[i]);
        pos = req[i];
        printf(" -> %d",pos);
    }
    
    // 2. Left side (reverse) - NO disk end jumps!
    for(int i=split-1;i>=0;i--){
        total += abs(pos - req[i]);
        pos = req[i];
        printf(" -> %d",pos);
    }
    
    printf("\nTotal Seek Time = %d\n",total);
    return 0;
}
