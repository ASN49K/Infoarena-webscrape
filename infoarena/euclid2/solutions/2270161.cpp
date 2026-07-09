#include <iostream>
#include <fstream>

using namespace std;

int cmmdc (int x, int y)
{
    if (x==0)
        return y;
    if (y==0)
        return x;
    if ((x&1)==0 && (y&1)==0)
        return 2*cmmdc(x>>1, y>>1);
    if ((x&1)==0)
        return cmmdc(x>>1, y);
    if ((y&1)==0)
        return cmmdc (x, y>>1);
    if (x>y)
        return cmmdc (x-y,y);
    cmmdc (x,y-x);
}

int main()
{
    int T;
    ifstream fin ("euclid2.in");
    ofstream fout ("euclid2.out");
    fin>>T;
    for (int i=0;i<T;i++)
    {
        int x,y;
        fin>>x>>y;
        fout<<cmmdc(x,y)<<"\n";
    }
    return 0;
}
