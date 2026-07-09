#include <iostream>
#include <fstream>

using namespace std;

int Cmmdc(int a,int b)
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
    int a,b,n,i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin >> n;
    for(i=1;i<=n;i++)
    {
        fin >> a >> b;
        fout << Cmmdc(a,b) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
