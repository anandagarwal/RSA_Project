#include<stdio.h>
#include<stdlib.h>
#include"func.h"
#include<math.h>
static int count=0;
void read(long long d,long long n)
{
	int j;
	long long i,val;
	long long a[MAX];
	FILE *fp;
	fp=fopen("e_file.txt","r");
	while(fscanf(fp,"%lld",&i)!=-1)
	{
		a[count]=i;
		++count;
	}
			
	fclose(fp);
	fp=fopen("d_file.txt","w");
	for(i=0;i<count;++i)
	{
		val=decrypt(a[i],d,n);
		fprintf(fp,"%lld\n",val);
	}	
	fclose(fp);
}





long long decrypt(long long a,long long d,long long n)
{
	
	long long i,j;
	long long M=1;
	FILE *fp;
	
	for(i=0;i<d;++i)
	{
	
		M=(M*a)%n;
	}
	
	return M;
}




