#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,n,c;
int main ()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        if(a<b)
        {
            c=a;
            a=b;
            b=c;
        }
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout<<a<<'\n';
    }

    return 0;
}
