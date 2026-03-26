#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, head;
    printf("Enter number of requests: ");
    scanf("%d",&n);
    int req[100], visited[100]={0};
    printf("Enter requests:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&req[i]);
    printf("Enter initial head: ");
    scanf("%d",&head);
    int pos = head, total = 0;
    printf("\nSeek Sequence: %d",pos);
    for(int i=0;i<n;i++){
        int min = 9999, index = -1;
        for(int j=0;j<n;j++){
            if(!visited[j]){
                int dist = abs(pos - req[j]);
                if(dist < min){
                    min = dist;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        total += min;
        pos = req[index];
        printf(" -> %d",pos);
    }
    printf("\nTotal Seek Time = %d\n",total);
    return 0;
}