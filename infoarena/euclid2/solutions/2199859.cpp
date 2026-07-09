#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(long long a,long long b)
{
    if(b==0)
        return a;
    else
        cmmdc(b,a%b);
}

int main()
{
    ifstream  fin("euclid2.in");
    ofstream fout("euclid2.out");
    int n;
    fin>>n;
    long long a,b;
    for(int i=0;i<n;i++)
        {
            fin>>a>>b;
            fout<<cmmdc(a,b)<<'\n';
        }
    return 0;
}
