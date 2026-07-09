#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int euclid(int a,int b)
{
    if(b>a)
    {
        swap(a,b);
    }
    int dif;
    dif=a-b;
    while(dif)
    {
        a=max(b,dif);
        b=min(b,dif);
        dif=a-b;
    }
    return b;
}

int main()
{
    int t,a,b;
    fin>>t;
    for(int i=1;i<=t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<endl;
    }
    return 0;
}
