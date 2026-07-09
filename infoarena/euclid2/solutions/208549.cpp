#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long t;

 int cmmdc(long a,long b){  
     if(b==0)  
         return a;  
     return cmmdc(b,a%b); 
}

int main()
{
	fin>>t;
	long i,a,b;
	for(i=1;i<=t;++i)
	   {
	   	   fin>>a>>b;
	   	   cout<<cmmdc(a,b)<<"\n";
	   	
	   	}
	 fin.close();
	 fout.close();
	 return 0;
}
