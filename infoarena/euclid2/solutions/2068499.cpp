#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T,a,b,i,r=1;

int main()
{
    in>>T;
    for (i=1;i<=T;i++)
    {   r=1;
        in>>a>>b;
        while(r)
        {   cout<<a<<" "<<b<<" "<<r<<"\n";
            r=a%b;
            a=b;
            b=r;
            cout<<a<<" "<<b<<" "<<r<<"\n";
        }
        out<<a<<"\n";
    }
    return 0;
}
