#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,d,i,mxab,mxd;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        if(a>b)
        {
            mxab=a;
        }
        else
            mxab=b;
        for(d=1;d<=mxab;d++)
        {
            if(a%d==0 && b%d==0)
            {
                mxd=d;
            }
        }
        out<<mxd<<"\n";
    }
    return 0;
}
