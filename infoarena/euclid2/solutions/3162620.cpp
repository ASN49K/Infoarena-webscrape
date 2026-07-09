#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,r;
int gcd(int a,int b)
{
    if(b==0 ) return a;
    return gcd(b,a%b);
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
