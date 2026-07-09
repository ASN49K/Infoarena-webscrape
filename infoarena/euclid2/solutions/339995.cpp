#include<fstream.h>

long cmmdc(long a, long b)
{
    if (!b) return a;
    return cmmdc(b,a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    long a,b,t,i;
    for (i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }
    
    return 0;
}
