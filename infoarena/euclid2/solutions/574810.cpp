#include<fstream> 
using namespace std; 
ifstream f("euclid2.in"); 
ofstream g("euclid2.out");
int cmmdc(int a,int b) 
{int c; 
while(b) {c=a%b; 
a=b; 
b=c;} 
return a;}
int main() 
{int t,a,b,i; 
f>>t; 
for(i=1;i<=t;i++) 
{f>>a; f>>b;
g<<cmmdc(a,b)<<'\n';}
}
