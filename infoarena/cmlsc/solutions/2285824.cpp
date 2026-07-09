#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,i,j,a[1026],b[1026],d[1026][1026],sol[1050],k;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>a[i];
    for(j=1;j<=m;j++)
        fin>>b[j];
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        if(a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i][j-1],d[i-1][j]);
    }
    i=n;
    j=m;
    while (d[i][j]!=0) {
		if (a[i]==b[j]) {
			sol[++k]=a[i];
			i--; j--;
		}
		else {
			if (d[i-1][j]>d[i][j-1])
				i--;
			else
				j--;
		}
	}
	fout<<k<<"\n";
	for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";
}
