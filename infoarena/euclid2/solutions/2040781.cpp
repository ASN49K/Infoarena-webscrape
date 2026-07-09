#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int recursiv(int a,int b)
{
    if(!b)
        return a;
    return recursiv(b,a%b);
}
int main()
{
    int a,b,n;
    fin>>n;
    for(int i=0;i<n;i++)
    {
        fin>>a>>b;
        fout<<recursiv(a,b)<<"\n";
    }
    return 0;
}
