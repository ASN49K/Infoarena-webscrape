#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int t,a,b,m,i;
    in>>t;
    while(t!=0)
    {
        in>>a>>b;
        while(b!=0)
        {
            m=b;
            b=a%b;
            a=m;
        }
        out<<a<<endl;
        t--;
    }
    return 0;
}
