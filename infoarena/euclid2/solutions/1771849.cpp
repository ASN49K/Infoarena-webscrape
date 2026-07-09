#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,n;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        if(a<b)
        {
            int c=a;
            a=b;
            b=a;
        }
        while(b!=0)
        {
          int  c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<'\n';
    }
    return 0;
}
