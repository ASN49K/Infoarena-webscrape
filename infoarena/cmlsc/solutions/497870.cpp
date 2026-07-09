#include<stdio.h>
using namespace std;
int n, m, a[1025], b[1025], d[1025][1025], sir[1025], nr=0;


	FILE* in = fopen("cmlsc.in", "r");
	FILE* out = fopen("cmlsc.out", "w");


void citire()
{
	fscanf(in, "%d %d", &n, &m);
	for(int i=1;i<=n;i++) { fscanf(in, "%d", &a[i]);
	fprintf(out, "%d", a[i]);
	}
}

int maxim(int a, int b)
{
	if(a>b) return a;
	return b;
}

void rezolva()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
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
	fprintf(out, "%d\n", nr); 
	for(int i=nr;i>=1;i--) fprintf(out, "%d ", sir[i]); 
	return 0;
}
