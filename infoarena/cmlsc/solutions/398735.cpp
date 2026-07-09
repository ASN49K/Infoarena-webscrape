#include <fstream>
std::ifstream in("cmlsc.in");
std::ofstream out("cmlsc.out");
unsigned short a[1024],b[1024],LCS[1024][1024];
void afiseaza(int i,int j)
{
	if(LCS[i][j])
     if(a[i]==b[j])
	 {
		 afiseaza(i-1,j-1);
		 out<<a[i]<<" ";
	 }
	 else
	 {
		 if(LCS[i][j]==LCS[i-1][j])
			 afiseaza(i-1,j);
		 else
			 if(LCS[i][j]==LCS[i][j-1])
				 afiseaza(i,j-1);
	 }
}
int main ()
{
	int m,n,i,j;
	in>>n>>m;
	for(i=1;i<=n;i++)
		in>>a[i];
	for(i=1;i<=m;i++)
		in>>b[i];
	LCS[0][0]=0;
	//Cel mai lung subsir comun
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i]==b[j])
				LCS[i][j]=LCS[i-1][j-1]+1;
			else
				if(LCS[i-1][j]>LCS[i][j-1])
					LCS[i][j]=LCS[i-1][j];
				else
					LCS[i][j]=LCS[i][j-1];
		}
	}
	out<<LCS[n][m]<<'\n';
	afiseaza(n,m);
}