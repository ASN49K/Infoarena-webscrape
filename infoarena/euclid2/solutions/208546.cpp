#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int t;

int cmmdc(int a,int b)
{
	int c;
	
	
	while(b)
	{
	   c=a%b;
 	   a=b;
 	   b=c;
 	   
   		}
    return a;
}

int main()
{
	fin>>t;
	int i,a,b;
	for(i=1;i<=t;++i)
	   {
	   	   fin>>a>>b;
	   	   cout<<cmmdc(a,b)<<"\.n";
	   	
	   	}
	 fin.close();
	 fout.close();
	 return 0;
}
