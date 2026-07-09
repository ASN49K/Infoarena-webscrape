#include<iostream>
#include<fstream>
int a[100000];
using namespace std;
int main()
{ int n,i,x,a,b,r;
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  fin>>n;
  for(i=1;i<=n;i++)
  {
	  fin>>a>>b;
	  if(a>b)
	  {
		  r=a%b;
		  if(r==0) fout<<b<<endl;
		  else  fout<<r<<endl;
	  }
	  else
	  {
		  r=b%a;
		  if (r==0) fout<<a<<endl;
		  else fout<<r<<endl;
	  }
  }
  fin.close();
  fout.close();
  return 0;
}
