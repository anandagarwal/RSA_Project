#include<stdio.h>
#include<stdlib.h>
#include"func.h"
#include<math.h>
static int count=0;
void read()
{
	int j;
	long long i;
	long long a[MAX];
	FILE *fp;
	fp=fopen("inputfile.txt","r");
	while(fscanf(fp,"%lld",&i)!=-1)
	{
		a[count++]=i;
	}
	fclose(fp);
	input(a);
	
}	



void write_e_file(long long e_array[])
{
	long long val;
	int i,j;
	FILE *fp;	
	fp=fopen("e_file.txt","w");
	for(i=0;i<count;++i)
	
	{
		val=e_array[i];
		fprintf(fp,"%lld\n",val);
	}
	fclose(fp);	
		
}	
void input(long long num[])
{
	long long e_array[MAX];
	int flag=0,flag2=0;
	long long p,q;
	long long m,n;
	long long e;
	long long d;
	long long encrypt_val,decrypt_val;
	int j,k;
	srand(time(NULL));
	
		//generating two prime numbers p & q.
	
		while(flag==0)
		{
			p=rand()%10000;
			flag=isPrime(p);
		}
		printf("the number p is %lld\n",p);	
		
		
		while(flag2==0)
		{
			q=rand()%10000;
			flag2=isPrime(q);	
		}	
		printf("the number q is %lld \n",q);

		//public key uses e & n for encryption.
		//private key uses n & d for decryption.
	
		n=p*q;
		m=(p-1)*(q-1);
	
		printf("the value of m is %lld \n",m);
		printf("the value of n is%lld \n",n);
	
		//Conditions for e:
		// 1<e<m, 
		// e & m should be coprime.
		e=generating_coprime(m);

		printf("the value of e is %lld\n",e);
		printf("the public key is{%lld,%lld}\n",e,n);

		d=gen_d(e,m,n);
		printf("the value of d is %lld\n",d);
		printf("the private key {%lld,%lld}\n\n",d,n);
		printf("ENCRYPTING...\n");
		

		for(j=0;j<count;++j)
		{
			//encrypting the given value using public keys- e & n.
			encrypt_val=encrypt(e,n,num[j]);
			//printf("the encrypted value is %lld \n",encrypt_val);
			e_array[j]=encrypt_val;
		}
		write_e_file(e_array);
	
		//Value to be decrypted using the private keys- n & d.
		//printf("Enter the value ton");
	//	scanf("%lld",&num2);
		int i;
		for(i=0;i<count;++i)
		{
			//printf("%lld\n",e_array[i]);
			decrypt(d,n,e_array[i]);
		}
	//	printf("the decrpted value is %lld\n",decrypt_val);

		printf("CHECK FOR e_file.txt GENERATED in ENCRYPTION FOLDER\nCOPY THE e_file.txt TO THE DECRYPTION FOLDER\n");

}
int isPrime(long long p1)
{
	long long x;
	long long s=2;
	if(p1%s==0)
	{
		return 0;
	}
	
	for(x=3;x<p1;++x)
	{
		if(p1%x==0)

		{
			return 0;
			break;
		}
		
		
	}
	if(x==(p1-1))
	{
		return 1;	
	}
}

//Conditions for e:
    	// 1<e<m, 
        // e & m should be coprime.

long long generating_coprime(long long m)
{
	long long e,temp;
	int g;
	srand(time(NULL));
	e=rand()%m;
	while(e>m)
	{
		e=rand()%m;

	}
	while(e>1 && e<m)
	{
		g=gcd(m,e);
		if(g!=1)
		{
			e=e+1;
		}
		else
		{
			return e;	
		}
	}
}

int gcd(long long m,long long n)
{
	if(n==0)
	{
		return m;
	}
	else
	{
		return gcd(n,m%n);
		
	}
}
long long gen_d(long long e,long long m,long long n)
{
	long long d=1,s;
	do
	{
		s=(d*e)%m;
		d++;	
	}while(s!=1);
	d=d-1;
	
	return d;
}
long long encrypt(long long e,long long n,long long num)
{
	long long i;
	long long C=1;
	for(i=0;i<e;++i)
	{
		C=(C*num)%n;
	}
	return C;
}
void decrypt(long long d,long long n,long long encrypt_val)
{
	
	long long i;
	long long M=1;
	for(i=0;i<d;++i)
	{
		M=(M*encrypt_val)%n;
	}
//	M=M%n;
	//printf("%lld\n",M);
}




