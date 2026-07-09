#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int T,a,b,r;
    fin>>T;
    if(T>=1 && T<=100000)
    {
        for(;T;T--)
        {
            fin>>a>>b;
            while(b)
            {
                r=a%b;
                a=b;
                b=r;
            }
            out<<a<<'\n';
        }
    }
    fin.close();
    out.close();
    return 0;
}
