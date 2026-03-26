#include<stdio.h>
int main(){
    int n, tq;
    printf("Enter No of Processes: ");
    scanf("%d",&n);
    int AT[n], BT[n], RT[n], WT[n], TAT[n], CT[n];
    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
        RT[i]=BT[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d",&tq);
    int time=0, completed=0;
    printf("\nRound Robin Gantt Chart:\n");
    while(completed<n){
        int flag=0;
        for(int i=0;i<n;i++){
            if(RT[i]>0 && AT[i]<=time){
                flag=1;
                printf("| P%d ",i+1);
                if(RT[i]>tq){
                    time+=tq;
                    RT[i]-=tq;
                }else{
                    time+=RT[i];
                    CT[i]=time;
                    TAT[i]=CT[i]-AT[i];
                    WT[i]=TAT[i]-BT[i];
                    RT[i]=0;
                    completed++;
                }
            }
        }
        if(!flag) time++;
    }
    printf("|\n");
    float totalWT=0,totalTAT=0;
    printf("Process AT BT WT TAT\n");
    for(int i=0;i<n;i++){
        printf("%d      %d  %d  %d  %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);
        totalWT+=WT[i];
        totalTAT+=TAT[i];
    }
    printf("Average WT = %.2f\n",totalWT/n);
    printf("Average TAT = %.2f\n",totalTAT/n);
    return 0;
}
