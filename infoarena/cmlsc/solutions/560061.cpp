#include<fstream.h>
int a[1024][1024];
int main ()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int M,N,v[1026],w[1026],i,j,max,c[1026],k=0;
	f>>M>>N;
	for(i=1;i<=M;i++) f>>v[i];
	for(i=1;i<=N;i++) f>>w[i];
	for(i=1;i<=M;i++) a[0][i]=0;
	for(i=1;i<=N;i++) a[i][0]=0;
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++)
		{
			if(w[i]==v[j]) a[i][j]=a[i-1][j-1]+1;
			else{
				if(a[i][j-1]>a[i-1][j]) max=a[i][j-1];
				else max=a[i-1][j];
				a[i][j]=max;
			}
		}
	}
	g<<a[N][M]<<"\n";
	i=N;j=M;
	while(i>0 && j>0)
	{
		if(w[i]==v[j]) {c[++k]=w[i];i--;j--;}
		else if(a[i][j]==a[i-1][j]) i--;
		else j--;
	}
	for(i=k;i>=1;i--) g<<c[i]<<" ";
	f.close();
	g.close();
	return 0;
}