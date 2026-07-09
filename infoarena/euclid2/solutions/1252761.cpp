#include <iostream>
#include <fstream>
using namespace std;
int cmmdc(int a,int b)
{
    int r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    int T, a,b, c;
    fin>>T;
    for(int i=1;i<=T;i++)
    {
        fin>>a>>b;
        c = cmmdc(a,b);
        fout<<c<<"\n";
    }
    fin.close();
    fout.close();
    return 0;
}
