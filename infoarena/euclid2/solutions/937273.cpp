#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{int t,a,b,i=1;
f>>t;
do{f>>a>>b;
while(a!=b)
    if(a>b)a=a-b;
else b=b-a;
g<<a;
g<<endl;i=i+1;}while(i<=t);}











