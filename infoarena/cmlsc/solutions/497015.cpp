#include<stdio.h>
using namespace std;
int n, m, a[1025], b[1025], d[1025][1025], sir[1025], nr=0;


	FILE* in = fopen("cmlsc.in", "r");
	FILE* out = fopen("cmlsc.out", "w");


void citire()
{
	fscanf(in, "%d %d", &m, &n);
	for(int i=1;i<=m;i++) fscanf(in, "%d", &a[i]);
	for(int j=1;j<=n;j++) fscanf(in, "%d", &b[j]);
}

int maxim(int a, int b)
{
	if(a>=b) return a;
	else return b;
}

void rezolva()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
			else d[i][j]=maxim(d[i-1][j], d[i][j-1]);
		}
}

void rezsir()
{
	for(int i=n, j=m; i && j; )
    {
      if(a[i] == b[j])
      {
          sir[++nr] = a[i];
          --i; --j;
      }
      else if(d[i][j-1] < d[i-1][j])
        --i;
      else
        --j;
	}
}

int main()
{
	citire();
	rezolva();
	rezsir();
	fprintf(out, "%d \n", d[m][n]); 
	for(int i=1;i<=nr;i++) fprintf(out, "%d ", sir[i]); 
}
