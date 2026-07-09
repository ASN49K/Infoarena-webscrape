#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int x, int y)
{
    int c;
    while(y!=0)
    {
        c=y;
        y=x%y;
        x=c;
    }
    return x;
}

int main()
{
    int  n,x,y;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>n;
    while(n>0)
    {
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
        n--;
    }
    fin.close();
    fout.close();
    return 0;
}
