#include <fstream>

using namespace std;

int abs_dif(int a,int b)
{
    if(a>b)
        return (a-b);
    return (b-a);
}

int cmmdc(int a,int b)
{
    //cout<<"cmmdc("<<a<<","<<b<<")\n";
    if(!b)
        return a;
    if(!a)
        return b;
    if(!(a&1))
    {
        if(!(b&1))
           return (cmmdc(a>>1,b>>1)<<1);
        else
           return cmmdc(a>>1,b);
    }
    else
    {
        if(!(b&1))
           return cmmdc(a,b>>1);
        else
           return cmmdc(abs_dif(a,b)>>1,min(a,b));
    }
}

int main()
{
    int t,a,b,i;
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    fin>>t;

    for(i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<'\n';
    }



    fin.close();
    fout.close();
    return 0;
}
