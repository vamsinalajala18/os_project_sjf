#include<stdio.h>
#include<conio.h>
#include<string.h>
int n;
int at[100],wt[100],tat[100],bt[100],ct[100];
char proc[20][20];
float avgtat,avgwt;
void input()
{
	int i;
	printf("\nEnter number of processors: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nEnter prosessor name: ");
		scanf("%s",proc[i]);
		printf("\nEnter arrival time of %s: ",proc[i]);
		scanf("%d",&at[i]);
		printf("\nEnter burst time of %s: ",proc[i]);
		scanf("%d",&bt[i]);
	}
}
int c[100];
int bt2[100];
void shortest_job_first()
{
	int i;
	char c[100],p1[20][20];
	int w=0,t,Tt=0,temp,temp1,j,bt1[100];
	for(i=0;i<n;i++)
	{
		bt1[i]=bt[i];
		c[i]='T';
		Tt=Tt+bt1[i];	
	}
	for(i=0;i<n;i++)
	{
		for(j=2;j<n;j++)
		{
			if(bt1[j-1]>bt[j])
			{
				temp=bt1[j-1];
				bt1[j-1]=bt1[j];
				bt1[j]=temp;
				temp=at[j-1];
				at[j-1]=at[j];
				at[j]=temp;
				strcpy(p1[j-1],proc[j-1]);
				strcpy(proc[j-1],proc[j]);
				strcpy(proc[j],p1[j-1]);
			}
		}
		
	}
	for(i=0;i<n;i++)
	{
		bt2[i]=bt1[i];
	}
	bool check=true;
	while(check)
	{
		for(i=0;i<n;i++)
		{
			if(i==0)
			{
				if(bt2[i]>10)
				{
					ct[i]=at[i]+10;
					bt2[i]=bt2[i]-10;
				}
				else
				{
					ct[i]=at[i]+bt2[i];
					bt2[i]=0;
				}
			}
			else 
			{
				if(at[i]<=ct[i-1])
				{
					if(bt2[i]>10)
					{
						ct[i]=ct[i-1]+10;
						bt2[i]=bt2[i]-10;
					}
					else 
					{
						ct[i]=ct[i-1]+bt2[i];
						bt2[i]=0;
					}
				}
			}
		}
		int k9=0;
		for(i=0;i<n;i++)
		{
			k9=bt2[i]+k9;
			
		}
		if(k9==0)
		{
			check=false;
		}
	}
		
	
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		if(tat[i]<0)
		{
			tat[i]=0;
		}
		wt[i]=tat[i]-bt[i];
		if(wt[i]<0)
		{
			wt[i]=0;
		}
	}
	float s1=0,s2=0;
	for(i=0;i<n;i++)
	{
		s1=s1+tat[i];
		s2=s2+wt[i];
	}
	avgtat=s1/n;
	avgwt=s2/n;
	printf("\n\nProcess\tAT\tBT\tTAT\tWT\n");
	printf("\n___________________________________________________________________________________________\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\n",proc[i],at[i],bt1[i],tat[i],wt[i]);
		printf("\n");
	}
	printf("\n\nAverage waiting time: %f",avgwt);
	printf("\nAverage turn around time: %f",avgtat);
}
int main()
{
	input();
	shortest_job_first();
	getch();
}

