#include <iostream>
#include<fstream>
using namespace std;
fstream f("euclid2.in",ios::in);
fstream g("euclid2.out",ios::out);
long long a,b,s,i;
int n;
int main()
{
    int n;
    f>>n;
  for(;n>=0;--n){
    f>>a>>b;
while(a!=b)
{if(a>b)
a=a-b;
else
b=b-a;}
if(a!=1)
g<<a<<endl;
else g<<0<<endl;
  }
return 0;
}
