#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int main()
{
    int n,i,a,b,art;
    fin>>n;
    for (i=1;i<=n;i++)
    {
        fin>>a>>b;
        if (a<b)
        {
            art=a;
            a=b;
            b=art;
        }
        while (b!=0)
        {
            art=a%b;
            a=b;
            b=art;
        }
        fout<<a<<endl;
    }
    return 0;
}
