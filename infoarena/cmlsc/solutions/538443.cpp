#include<stdio.h>

FILE* f;
FILE* ff;
int* A;
int* B;
int M,N;
int* solutie;
int lungimeSolutie;

void initFiles(int &M, int &N)
{
	f=fopen("cmlsc.in","r");
	fscanf(f,"%d%d",&M,&N);
	A=new int [M];
	B=new int [N];
	for (int i=0;i<M;i++)
		fscanf(f,"%d",&A[i]);
	for (int i=0;i<N;i++)
		fscanf(f,"%d",&B[i]);
	ff=fopen("cmlsc.out","w");
}

void calculare(int* s)
{
	int *v1, *v2, v1l, v2l;
	if (M<N) 
	{
		v1=A;
		v2=B;
		v1l=M;
		v2l=N;
	}
	else 
	{
		v1=B;
		v2=A;
		v1l=N;
		v2l=M;
	}

	int i,j,k=0;
	for (i=0;i<v1l;i++)
		if (s[i])
		{
			for (j=k;j<v2l;j++)
				if (v1[i]==v2[j]) {k=j+1; break;}
		 if (j==v2l) return;
		}
	k=0;
	for (i=0;i<v1l;i++)
		if (s[i])
			k++;
	if (k>lungimeSolutie) 
	{
		lungimeSolutie=k;
		int l=0;
		for (i=0;i<v1l;i++)
			if (s[i]) 
			{
				solutie[l]=v1[i];
				l++;
			}
	}
}

void afisare()
{
	int i;
	fprintf(ff,"%d\n",lungimeSolutie);
	for (i=0;i<lungimeSolutie;i++)
		fprintf(ff,"%d ",solutie[i]);
}

void back(int n)
{
	int *s;
	s=new int[n];
	int k=0;
	s[k]=-1;
		while (k>=0)
			if (s[k]<1)
			{
				s[k]++;
					if (k==n-1)
						calculare(s);
					else s[++k]=-1;
			}
			else k--;
}

int main()
{
	initFiles(M,N);
	
	solutie=new int[(M<N)?M:N];
	back((M<N)?M:N);

	afisare();

	fclose(f);
	fclose(ff);
	
	return 0;
}