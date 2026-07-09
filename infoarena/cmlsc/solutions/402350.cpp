#include<fstream.h>
int main()
{ ifstream f1("fisier.in");
  ofstream g1("fisier.out");
  int a[1024],b[1024],m,n,i,j;
  f1>>m>>n;
  for(i=0;i<m;i++)
      f1>>a[i];
  for(j=0;j<n;j++)
	  f1>>b[j];
  f1.close();
  for(i=0;i<m;i++)
	  for(j=0;j<n;j++)
		if( i<i+1 && j<j+1 && a[i]==b[j])
		  { g1<<" "<<a[i];
          }
 g1.close();		  
  return 0;
}



