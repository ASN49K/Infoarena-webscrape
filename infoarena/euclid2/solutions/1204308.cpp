# include <iostream.h>

typedef unsigned long ulong;

ulong cmmdc( ulong a, ulong b)
{
    if (!b)
        return a;
    else 
        return cmmdc(b,a%b);
}

int main()
{
    ulong t,a,b;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;
    for (i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}