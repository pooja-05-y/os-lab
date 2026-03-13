#include <stdio.h>
#include <limits.h>

struct process{
    int pid, at, bt, pr, rt, ct, tat, wt, start;
};

int main()
{
    int n,time=0,completed=0,sumtat=0, sumwt=0, sumrt=0,min;
    float avgtat, avgwt, avgrt;
    struct process p[20];
    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);

        p[i].pid=i+1;
        p[i].rt=p[i].bt;
        p[i].start=-1;
    }

    while(completed<n)
    {
        min=-1;
        int best_pr = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].rt>0)
            {
                if(p[i].pr < best_pr)
                {
                    best_pr = p[i].pr;
                    min=i;
                }
            }
        }

        if(min==-1)
        {
            time++;
            continue;
        }

        if(p[min].start==-1)
            p[min].start=time;

        p[min].rt--;
        time++;

        if(p[min].rt==0)
        {
            completed++;

            p[min].ct=time;
            p[min].tat=p[min].ct - p[min].at;
            p[min].wt=p[min].tat - p[min].bt;
        }
    }

    printf("\nPID\t AT\t BT\t PR\t CT\t TAT\t WT\t RT\t\n");

    for(int i=0;i<n;i++)
    {
        sumtat += p[i].tat;
        sumwt += p[i].wt;
        sumrt += p[i].rt;

        int response = p[i].start - p[i].at;

        printf("P%d\t  %d\t  %d\t  %d\t  %d\t  %d\t  %d\t  %d\t\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt,response);
    }

    avgtat = (float)sumtat/n;
    avgwt  = (float)sumwt/n;
    avgrt  = (float)sumrt/n;

    printf("\nAverage TAT: %.2f", avgtat);
    printf("\nAverage WT: %.2f", avgwt);
    printf("\nAverage RT: %.2f\n", avgrt);

    return 0;
}
