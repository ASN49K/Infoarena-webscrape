#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    while(a && b)
    {
        if(a>b)
            a%=b;
        else
            b%=a;
    }
    if(a)
        return a;
    return b;
}

int main()
{
    int a,b,t;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    return 0;
}
