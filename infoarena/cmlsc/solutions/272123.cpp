#include <fstream>
#include <algorithm>  
using namespace std; 
const char in[]="cmlsc.in";
const char out[]="cmlsc.out";

int n,m,a[1500],b[1500];

void citire()
{
	ifstream fin(in);
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	for(int i=1;i<=n;i++)
		fin>>b[i];
}

int main()
{
	citire();
	int dimsec=0,csec[1500],dim=0,c[1500],ultima_pozitie=1,k=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=ultima_pozitie;j<=n;j++)
			if(a[j]==b[i])
			{
				ultima_pozitie=j;
				dimsec++;
				csec[k]=b[i];
				k++;
			}
		if(ultima_pozitie==n)
			if(dim<dimsec)
			{
				dim=dimsec;
				dimsec=0;
				for(k=1;k<=dim;k++)
					c[k]=csec[k];
			}
	}
	ofstream fout(out);
	fout<<dim<<'\n';
	for(int i=1;i<=dim;i++)
		fout<<c[i]<<' ';
	return 0;
}