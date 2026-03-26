#include<stdio.h>
int main(){
    int n, frames;
    printf("Enter reference string length: ");
    scanf("%d",&n);
    printf("Enter number of frames: ");
    scanf("%d",&frames);
    int pages[50], f[10], time[10];
    printf("Enter pages:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);
    for(int i=0;i<frames;i++){
        f[i] = -1;
        time[i] = 0;
    }
    int faults=0, count=0;
    printf("\nPage\t");
    for(int i=0;i<frames;i++) printf("F%d\t",i+1);
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
        if(found){
            for(int j=0;j<frames;j++)
                printf("%d\t",f[j]==-1? -1:f[j]);
            printf("H\n");
        }
        else{
            int min=time[0], pos=0;
            for(int j=1;j<frames;j++){
                if(time[j]<min){
                    min=time[j];
                    pos=j;
                }
            }
            f[pos]=pages[i];
            count++;
            time[pos]=count;
            faults++;
            for(int j=0;j<frames;j++)
                printf("%d\t",f[j]==-1? -1:f[j]);
            printf("M\n");
        }
    }
    printf("Total Page Faults = %d\n",faults);
    return 0;
}