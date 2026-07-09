#include<fstream> 
using namespace std; 
int main()
{ 
ifstream f("euclid2.in"); 
ofstream g("euclid2.out");
int i,n,a,b,r; 
f>>n; 
for(i=0;i<n;i++) 
{ 
f>>a>>b; 
r=a%b; 
while(r!=0) 
{ 
a = b; 
b = r; 
r = a%b; 
} 
g<<b<<endl; 
} 
f.close(); 
g.close(); 
return 0; 
}