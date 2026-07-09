#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int v[100001];
int main()
{
    int t,a,b,r,i;
    fin>>t;
    for(i=0;i<t;i++)
    {
        fin>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        v[i]=a;
    }
    for(i=0;i<t;i++)
        fout<<v[i]<<'\n';
    return 0;
}
