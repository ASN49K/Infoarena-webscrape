#include<fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main()
{  int a[1025],b[1025],m,n,i,c[1025][1025]={0},j,r[1025],poz;
   fin>>m>>n;
   for(i=1;i<=m;i++)
	fin>>a[i];
   for(i=1;i<=n;i++)
	fin>>b[i];
   for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	  if(a[j]==b[i])
		 c[i][j]=c[i-1][j-1] + 1;
      else if(c[i-1][j]>c[i][j-1])
              c[i][j]=c[i-1][j];
		   else c[i][j]=c[i][j-1];
	poz=c[n][m];
	fout<<poz<<endl;	   
	for(i=n,j=m;poz;)
      if(a[j]==b[i]) { r[poz--]=a[j]; j--;i--; }
      else if(c[i-1][j]==c[i][j]) i--;
           else if (c[i][j-1]==c[i][j]) j--;
    for(i=1;i<=c[n][m];i++)
      fout<<r[i]<<' ';		
    return 0;
	fin.close();
	fout.close();
}