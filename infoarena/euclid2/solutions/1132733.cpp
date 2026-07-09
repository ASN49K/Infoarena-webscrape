#include <iostream>
#include <fstream>
using namespace std;

ifstream i("euclid2.in");
ofstream j("euclid2.out");

int main()
{
int d,t,a,b;
i>>t;
d=0;
while(d<t)
    {i>>a>>b;
    while(a!=b)
        {if(a<b)
            b=b-a;
        if(a>b)
            a=a-b;
        }
    j<<a<<'\n';
    d++;
    }

    return 0;
}
