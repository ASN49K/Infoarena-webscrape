#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,i=1,d;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    while(i<=t)
    {
        in>>a>>b;
        while(a!=b && a!=0 && b!=0)
        {
            if(a>b)
            {
                d=b*(a/b);
                a=a-d;
            }
            else
            {
                if(a<b)
                {
                    d=a*(b/a);
                    b=b-d;
                }
            }
        }
        if(a!=0)
            out<<a<<endl;
        else
            out<<b<<endl;
        i++;
    }
    return 0;
}
