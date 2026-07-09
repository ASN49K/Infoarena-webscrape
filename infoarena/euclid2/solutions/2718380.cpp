#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{   int n,a,b;
    fin>>n;
    for (int i=1;i<=n;i++)
    {
        fin>>a>>b;
        if (a-b==1 || b-a==1)
            fout<<1<<'\n';
        else
         while(a != b)
        if(a > b)
            a -= b;
        else
            b -= a;
        fout<<a<<'\n';
    }
    return 0;
}
