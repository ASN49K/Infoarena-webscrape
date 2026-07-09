#include <iostream>
#include<fstream>

using namespace std;
ifstream f ("euclid2.in ");
ofstream g ("euclid2.out");
int euclid(int a,int b)
{ int c;
    while(b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
int main()
{int t,a,b,i;
f>>t;
for(i=1;i<=t;i++){f>>a>>b;
     g<<euclid(a,b)<<"\n";}

    return 0;
}
