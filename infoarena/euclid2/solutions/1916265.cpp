#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,i,j;
int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=t;i>0;i--)
    {
        in>>a>>b;
        for(j=min(a,b);j>0;j--)
            if(a%j==0&&b%j==0)
        {
            out<<j<<"\n";
            break;
        }
    }
    return 0;
}
