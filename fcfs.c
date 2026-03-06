#include <stdio.h>
int main(){
    int n,i,at[100],bt[100],ct[100],tat[100],wt[100],rt[100],sum1,sum2,sum3;
    sum1=sum2=sum3=0;
    float avgtat,avgwt,avgrt;
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

    for(i=0;i<n;i++){
        sum1 += tat[i];
        sum2 += wt[i];
        sum3 += rt[i];
    }

    avgtat = (float)sum1 / n;
    avgwt  = (float)sum2 / n;
    avgrt  = (float)sum3 / n;

    printf("\nAverage TAT: %.2f\nAverage WT: %.2f\nAverage RT: %.2f\n",avgtat, avgwt, avgrt);

    //calc avg
//    for(i=0;i<n;i++){
//        tatsum+=tat[i];
//        wtsum+=wt[i];
//        rtsum+=rt[i];
//    }
//
//    printf("avg tat=%f",(tatsum/n));
//    printf("avg wt=%f",(wt/n));
//    printf("avg rt=%f",(rt/n));

    return 0;
}
