#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int a,b,n,r;
    fin>>n;
    while(n)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        fout<<a;
        if(n!=1) fout<<'\n';
        --n;
    }
    return 0;
}
