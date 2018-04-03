#include<stdio.h>
int main()
{
	int n,i,total_time = 0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int burst_time[50], waittime[100], r_time[100], turn_around_time[100];

	for(i = 0; i < n; i++)
	{
		printf("\nEnter the burst time for process %d: ",(i+1));
		scanf("%d",&burst_time[i]);
			r_time[i] = burst_time[i];
		total_time =total_time + burst_time[i];
	}
	printf("\nEnter the time quantum: ");
	int tq;
	scanf("%d",&tq);
	int timecounter = 0;
	while(timecounter <	total_time )
	{

		for(i = 0; i < n;)
		{
			if(r_time[i] > tq)
			{
				
				r_time[i] =r_time[i]- tq;
				timecounter = timecounter + tq;
			i++;
			}
			if(r_time[i]== tq)
			{
				r_time[i] = 0;
				timecounter =timecounter + tq;
				turn_around_time[i] = timecounter;
			i++;
			}
			if(r_time[i]< tq && r_time[i] > 0)
			{
				timecounter =timecounter + r_time[i];
				r_time[i] = 0;	
				turn_around_time[i]  = timecounter;
			i++;
			}
		if(r_time[i]==0)
		{
			i++;
		}
	
		}
	}
		
	float avgwaittime =0;
	printf("\nProcess\tbt     \t                Ct      \t        Wt      ");
	for(i = 0; i < n; i++)
	{
		waittime[i] =turn_around_time[i]  - burst_time[i];
		printf("\nP%d\t%d\t\t\t%d\t\t\t%d",(i+1),burst_time[i],turn_around_time[i] ,waittime[i]);
		avgwaittime =avgwaittime+ waittime[i];
	}
	avgwaittime = avgwaittime/n;
	printf("\nThe average waiting time is %f",avgwaittime);
	
}
