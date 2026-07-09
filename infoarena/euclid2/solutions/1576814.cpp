#include <iostream>
using namespace std;
int main()
{
    int a,b,r,n,i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>T;
    for(i=1;i<=n;i++)
        fin>>a>>b;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }fout<<a;
    fin.close();
    fout.close();

    return 0;
}
