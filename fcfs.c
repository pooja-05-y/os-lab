#include <stdio.h>
int main(){
    int n,i,at[100],bt[100],ct[100],tat[100],wt[100],rt[100];
    printf("enter no of processes required");
    scanf("%d",&n);
    //input at
    for (int i=0; i<n; i++){
        printf("enter arrival time for process %d:",i+1);
        scanf("%d",&at[i]);
    }

    //input bt
    for (int i=0; i<n; i++){
        printf("enter burst time for process %d:",i+1);
        scanf("%d",&bt[i]);
    }

    //calc ct
    ct[0] = at[0] + bt[0];

    for(i=1;i<n;i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    //calc tat,wt,rt
    for(i=0;i<n;i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];
    }


    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}
