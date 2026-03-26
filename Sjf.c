#include<stdio.h>
int main(){
    int n;
    printf("Enter No of Processes: ");
    scanf("%d",&n);
    int AT[n], BT[n], WT[n], TAT[n], CT[n], done[n];
    for(int i=0;i<n;i++){
        done[i]=0;
        printf("\nProcess %d\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&AT[i]);
        printf("Burst Time: ");
        scanf("%d",&BT[i]);
    }
    int time=0, completed=0;
    printf("\nSJF Gantt Chart:\n");
    while(completed<n){
        int idx=-1, min=99999;
        for(int i=0;i<n;i++){
            if(AT[i]<=time && !done[i] && BT[i]<min){
                min=BT[i];
                idx=i;
            }
        }
        if(idx==-1){
            time++;
        }else{
            printf("| P%d ",idx+1);
            WT[idx]=time-AT[idx];
            time+=BT[idx];
            CT[idx]=time;
            TAT[idx]=CT[idx]-AT[idx];
            done[idx]=1;
            completed++;
        }
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
