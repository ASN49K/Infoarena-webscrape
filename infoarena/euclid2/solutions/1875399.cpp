#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,a,b,maxim=1;
    in>>n;
    for(int i=1;i<=n;i++)
    {
        in>>a>>b;
        if(a<b)
        {
            for(int j=1;j<=a;j++)
            {
                if(((a%j==0)&&(b%j==0))&&(j>=maxim)) maxim=j;
            }
        }
        else for(int j=1;j<=b;j++)
            {
                if(((a%j==0)&&(b%j==0))&&(j>=maxim)) maxim=j;
            }
            out<<maxim<<endl;
            maxim=1;
    }
    return 0;
}
