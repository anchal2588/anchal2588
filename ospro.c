#include<stdio.h>
#include<conio.h>
int main()
{
  printf("\t\t\t..................... process scheduling .....................\n\n\n\n");
  long int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n ); 
  double priority[n],sum1=0,sum2=0,burst_time[n],arrival_time[n],waiting_time[n],turnaround_time[n], process[n], obj, completion_time[n],min,final_wait, final_turnaround, avg_wait, avg_turnaround;
  for(i=0;i<n;i++)
  {
    printf("\nEnter burst time for process [%d] : ", i+1 );
    scanf("%lf", &burst_time[i]);
    printf("Enter arrival time for process [%d] : ", i+1 );
    scanf("%lf", &arrival_time[i] );
    process[i]=i+1;
  }

  printf("\n\n\t\t\t--:process table:--\n\n");
  printf("\t\t.......................................\n");
  printf("\t\t| process | burst time | arrival time |\n");
  printf("\t\t.......................................\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],burst_time[i],arrival_time[i]);
  }
    printf("\t\t\........................................\n");


  printf("\n\n\t\t--: sorting process table a/c to arrival time :--\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrival_time[i]<arrival_time[j])
      {
        
        obj = burst_time[j];
        burst_time[j] = burst_time[i];
        burst_time [i] = obj;
  
        obj = process[j];
        process[j] = process[i];
        process[i] = obj;

        obj = arrival_time[j];
        arrival_time[j] = arrival_time[i];
        arrival_time[i] = obj;
      
      }
    }
  }
  printf("\t\t.......................................\n");
  printf("\t\t| process | burst time | arrival time |\n");
  printf("\t\t.......................................\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],burst_time[i],arrival_time[i]);
  }
    printf("\t\t.......................................\n");

  long int k = 1;
  double b_sum = 0;
  for(j=0;j<n;j++)
  {
    b_sum = b_sum + burst_time[j];
    min = burst_time[k];

    for(i=k;i<n;i++)
    {
      if((b_sum >= arrival_time[i])&&(burst_time[i]<min))
      {
        obj = burst_time[k];
        burst_time[k] = burst_time[i];
        burst_time[i] = obj;

        obj = arrival_time[k];
        arrival_time[k] = arrival_time[i];
        arrival_time[i] = obj;

        obj = process[k];
        process[k] = process[i];
        process[i] = obj;
      }
    }
    k++;
  }
  waiting_time[0] = 0;
  for(i=1;i<n;i++)
  {
    sum1 += burst_time[i-1];
    waiting_time[i] = sum1 - arrival_time[i];
    final_wait += waiting_time[i]; 
  }
  avg_wait = final_wait/n;
  for(i=0;i<n;i++)
  {
    sum2 += burst_time[i];
    turnaround_time[i] = sum2 - arrival_time[i];
    final_turnaround += turnaround_time[i];
  }
  avg_turnaround=final_turnaround/n;
printf("\n\n\t\t\t\t\t--:new table:--\n\n");
  printf("\t\t.............................................................................\n");
  printf("\t\t| process | burst time | arrival time |  waiting time  |  turnaround time   |\n");
  printf("\t\t.............................................................................\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],burst_time[i],arrival_time[i],waiting_time[i],turnaround_time[i]);
  }
    printf("\t\t............................................................................\n");
  
  completion_time[0] = burst_time[0];
  for(i=1;i<n;i++)
  {
    completion_time[i] = completion_time[i-1] + burst_time[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+waiting_time[i]/completion_time[i];
  }


  printf("\n\n\t\t--:final table after prioritizing the process a/c to SJF without preemption :--\n\n");
  printf("\t\t.............................................................................\n");
  printf("\t\t| process | burst time | arrival time |  waiting time  |  turnaround time  |\n");
  printf("\t\t.............................................................................\n");
  printf("\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |        %0.0lf          |\n",process[0],burst_time[0],arrival_time[0],waiting_time[0],turnaround_time[0]);
  for(i=n-1;i>0;i--)
  {
    printf("\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf         |\n",process[i],burst_time[i],arrival_time[i],waiting_time[i],turnaround_time[i]);
  }
    printf("\t\t...........................................................................\n");

  printf("\n\n\naverage turnaround time : %lf",avg_turnaround);
  printf("\n\average waiting time        : %lf\n\n",avg_wait);
  
  getch();
  return 0;
}
