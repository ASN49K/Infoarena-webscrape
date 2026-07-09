#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout ("euclid2.out");

int cmmdc(int a,int b)
{
    if (a<b)
    {
        while (a!=0)
        {
            int r=b%a;
            b=a;
            a=r;
        }
        return b;
    }
    else
        {
        while (b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
}

int main()
{ int t,a,b;

    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
