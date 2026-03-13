#include <stdio.h>

struct process{
    int pid, at, bt, pr, ct, tat, wt, rt, completed;
};

int main()
{
    int n,time=0,completed=0,min,sumtat=0, sumwt=0, sumrt=0;
    float avgtat, avgwt, avgrt;
    struct process p[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter AT BT Priority for P%d: ",i+1);
        scanf("%d %d %d",&p[i].at,&p[i].bt,&p[i].pr);
        p[i].pid=i+1;
        p[i].completed=0;
    }

    while(completed<n)
    {
        min=-1;

        for(int i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].completed==0)
            {
                if(min==-1 || p[i].pr < p[min].pr)
                    min=i;
            }
        }

        if(min==-1)
        {
            time++;
        }
        else
        {
            p[min].rt = time - p[min].at;
            time += p[min].bt;

            p[min].ct = time;
            p[min].tat = p[min].ct - p[min].at;
            p[min].wt = p[min].tat - p[min].bt;

            p[min].completed=1;
            completed++;
        }
    }

    printf("\nPID\t AT\t BT\t PR\t CT\t TAT\t WT\t RT\t\n");


    for(int i=0;i<n;i++)
    {
        sumtat += p[i].tat;
        sumwt += p[i].wt;
        sumrt += p[i].rt;

        printf("P%d\t  %d\t  %d\t  %d\t  %d\t  %d\t  %d\t  %d\t\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
    }

    avgtat = (float)sumtat/n;
    avgwt  = (float)sumwt/n;
    avgrt  = (float)sumrt/n;

    printf("\nAverage TAT: %.2f", avgtat);
    printf("\nAverage WT: %.2f", avgwt);
    printf("\nAverage RT: %.2f\n", avgrt);


    return 0;
}
