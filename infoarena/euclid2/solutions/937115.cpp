#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{int t,a,b,i;
f>>t;
for(i=1;i<=t;i++)do{f>>a>>b;
while(a!=b)
    if(a>b)a=a-b;
else b=b-a;
g<<a;
g<<endl;}while(!f.eof());}











