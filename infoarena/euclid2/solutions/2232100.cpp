#include <iostream>
#include <fstream>
using namespace std;
int t,a,b,diviz;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    in>>t;

    for(int i=1;i<=t;i++)
    {
        in>>a>>b;diviz=1;
        if(a%2==0 && b%2==0)
        {
           while(a%2==0 && b%2==0)
                {
                    a/=2;b/=2;
                    diviz*=2;
                }
        }
        for(int j=3;j<=40001 && a>=j && b>=j;j+=2)
        {
            if(a%j==0 && b%j==0)
            {
                while(a%j==0 && b%j==0)
                {
                    a/=j;b/=j;
                    diviz*=j;
                }
            }
        }
        out<<diviz<<'\n';
    }
    return 0;
}
