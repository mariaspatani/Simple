#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    int req[100], left[100], right[100];
    int disk_size = 200;
    printf("Enter requests:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);
    printf("Enter initial head: ");
    scanf("%d",&head);
    int l=0, r=0;
    for(int i=0;i<n;i++){
        if(req[i] < head) left[l++] = req[i];
        else right[r++] = req[i];
    }
    for(int i=0;i<l-1;i++)
        for(int j=i+1;j<l;j++)
            if(left[i] > left[j]){
                int t=left[i]; left[i]=left[j]; left[j]=t;
            }
    for(int i=0;i<r-1;i++)
        for(int j=i+1;j<r;j++)
            if(right[i] > right[j]){
                int t=right[i]; right[i]=right[j]; right[j]=t;
            }
    int pos=head, total=0;
    printf("\nSeek Sequence: %d",pos);
    for(int i=0;i<r;i++){
        total += abs(pos - right[i]);
        pos = right[i];
        printf(" -> %d",pos);
    }
    total += abs(pos - (disk_size-1));
    pos = disk_size-1;
    total += abs(pos - 0);
    pos = 0;
    printf(" -> %d",pos);
    for(int i=0;i<l;i++){
        total += abs(pos - left[i]);
        pos = left[i];
        printf(" -> %d",pos);
    }
    printf("\nTotal Seek Time = %d\n",total);
    return 0;
}