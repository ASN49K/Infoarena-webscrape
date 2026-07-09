#include <iostream>
#include <fstream>

using namespace std;

int cmmdc(int a, int b)
{
    int r;

    r=a%b;

    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }

    return b;
}

int main()
{
    ifstream fin("euclid2.txt");
    ofstream fout("euclid2out.txt");

    int n,a,b;

    fin>>n;

    while(n>0)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
        n--;
    }

    return 0;
}
