#include <fstream.h>

long cmmdc(long a, long b)
{
     if(!b) return a;
     return cmmdc(b,a%b);
}

int main()
{
    long a,b;
    ifstream fin("cmmdc.in");
    fin>>a>>b;
    fin.close();
    
    long x;
    x=cmmdc(a,b);
    if(x==1) x=0;
    
    ofstream fout("cmmdc.out");
    fout<<x;
    fout.close();
    
    return 0;
}
