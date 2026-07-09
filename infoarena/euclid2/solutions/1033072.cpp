#include<iostream>
#include<fstream>
using namespace std;
int main()
{int a,b,r,T,i;
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
g<<b<<endl;
}

return 0;
}
