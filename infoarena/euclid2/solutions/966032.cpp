#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t, a,b;
int main()
{ f>>t;
for(int i=1;i<=t;i++)
{
f>>a>>b;
while(a!=b)
    if(a<=b)b=b-a;
    else a=a-b;
    g<<a<<endl;
}
f.close();
g.close();
}
