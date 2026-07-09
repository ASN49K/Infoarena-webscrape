#include<fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int a,b,t;

int rezultat(int a,int b)
{
    int r=a;
    do
    {
        a=b;
        b=r;
        r=a%b;
    }while(r!=0);
    return b;
}

int main()
{
    fin>>t;
    for(;t>=1;t--)
    {
        fin>>a>>b;
        fout<<rezultat(a,b)<<'\n';
    }
    return 0;
}
