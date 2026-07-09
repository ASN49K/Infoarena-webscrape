#include<iostream>
#include<fstream>
int a[100000];
using namespace std;
int main()
{ int n,i,x,a,b;
  ifstream fin("euclid2.in");
  ofstream fout("euclid2.out");
  fin>>n;
  for(i=1;i<=n;i++)
  {
	  fin>>a>>b;
	  while(a!=b)
	  {
		  while(a>b)
		  {
			  a=a-b;
		  }
		  while(b>a)
		  {
			  b=b-a;
		  }
	  }
	  fout<<a<<endl;
  }
  fin.close();
  fout.close();
  return 0;
}
