#include<stdio.h>
int main(){
    int n;
    printf("Enter No of Processes: ");
    scanf("%d",&n);
    int AT[n], BT[n], WT[n], TAT[n], CT[n];
    for(int i=0;i<n;i++){
        printf("\nProcess %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
    }
    int time=0;
    printf("\nFCFS Gantt Chart:\n");
    for(int i=0;i<n;i++){
        if(time<AT[i]) time=AT[i];
        printf("| P%d ",i+1);
        WT[i]=time-AT[i];
        time+=BT[i];
        CT[i]=time;
        TAT[i]=CT[i]-AT[i];
    }
    printf("|\n0");
    time=0;
    for(int i=0;i<n;i++){
        if(time<AT[i]) time=AT[i];
        time+=BT[i];
        printf("   %d",time);
    }
    float totalWT=0,totalTAT=0;
    printf("\nProcess AT BT WT TAT\n");
    for(int i=0;i<n;i++){
        printf("%d      %d  %d  %d  %d\n",i+1,AT[i],BT[i],WT[i],TAT[i]);
        totalWT+=WT[i];
        totalTAT+=TAT[i];
    }
    printf("Average WT = %.2f\n",totalWT/n);
    printf("Average TAT = %.2f\n",totalTAT/n);
    return 0;
}
