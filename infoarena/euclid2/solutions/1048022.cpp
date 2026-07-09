#include<iostream>
#include<fstream>
using namespace std;
int main()
{int T,i;
long int a,b,r;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
f>>T;
for(i=0;i<T;i++)
{f>>a;
f>>b;
r=a%b;
while(r!=0)
    {a=b;
    b=r;
    r=a%b;
    }
g<<b<<'\n';
}

return 0;
}
