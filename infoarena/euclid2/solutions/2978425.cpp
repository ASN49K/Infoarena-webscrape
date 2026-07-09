#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long int cmmdc(long long int a,long long int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    long long int a,b;
    int t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }

    return 0;
}
