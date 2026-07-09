#include<fstream> 
using namespace std; 
ifstream f("euclid2.in"); 
ofstream g("euclid2.out");
int cmmdc(int a,int b) 
{if(!b) return a; 
return cmmdc(b,a%b);}
int main() 
{int t,a,b,i; 
f>>t; 
for(i=1;i<=t;i++) 
{f>>a; f>>b;
g<<cmmdc(a,b)<<'\n';}
}
