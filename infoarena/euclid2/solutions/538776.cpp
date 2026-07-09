#include<iostream>
#include<fstream>
int a[100000];
using namespace std;
int main()
{ int n,i,x,a,b,r,min;
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  fin>>n;
  for(i=1;i<=n;i++)
  {
	  fin>>a>>b;
	  while((a!=0)&&(b!=0))
	  {
		  if(a>=b)
		  {
			  a=a%b;
		  }
		  else
		  {
			  b=b%a;
		  }
	  }
	  if(b==0) fout<<a<<'\n';
	  if(a==0) fout<<b<<'\n';
  }
  fin.close();
  fout.close();
  return 0;
}
