#include<stdio.h>
struct process
{
 char name;
 int at,bt,ct,wt,tt;
 int completed;
 float ntt;
 int priority;
}p[10];
int n;

void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
{
 if(p[i].at>p[j].at)
 {
  temp=p[i];
  p[i]=p[j];
  p[j]=temp;
 }
}
}
void main()
{
 int i,j,time,sum_bt=0;
 char c;
        float avgwt=0;
 printf("Enter no of processes:");
 scanf("%d",&n);
 for(i=0,c='A';i<n;i++,c++)
 {
 p[i].name=c;
 printf("\nEnter the arrival time of process%c: ",p[i].name);
 scanf("%d%",&p[i].at);
 printf("\n enter the burst time of process%c: ",p[i].name);
 scanf("\n %d",&p[i].bt);
 p[i].completed=0;
 sum_bt+=p[i].bt;

}
sortByArrival();

printf("\nName\tArrival Time\tBurst Time\tWaiting Time\tTurnAround Time\t Normalized TT\t\t priority");
  for(time=p[0].at;time<sum_bt;)
  {
  
   float hrr=-9999;
   int loc;
  for(i=0;i<n;i++)
  {
  
   if(p[i].at<=time && p[i].completed!=1)
            {
              float temp=(p[i].bt + (time-p[i].at))/p[i].bt;
              if(hrr < temp)
               {
                hrr=temp;
                loc=i;
               }
          
   }
   }
  
  
   time+=p[loc].bt; 
   p[loc].wt=time-p[loc].at-p[loc].bt;
   p[loc].tt=time-p[loc].at;
   p[loc].ntt=((float)p[loc].tt/p[loc].bt);
   p[loc].completed=1;
   p[loc].priority=1+(p[loc].wt/p[loc].bt);
   avgwt+=p[loc].wt;
 
printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d\t\t%f\t\t%d",p[loc].name,p[loc].at,p[loc].bt,p[loc].wt,p[loc].tt,p[loc].ntt,p[loc].priority);
  }

printf("\nAverage waiting time:%f\n",avgwt/n);
}
