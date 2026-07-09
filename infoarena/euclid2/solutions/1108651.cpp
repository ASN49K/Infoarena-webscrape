#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,r,cmmdc,i;
int main()
{
    fin >> n;
    for(i=1;i<=n;i++)
    {
        fin >> a >> b;
        r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        cmmdc=b;
        fout << cmmdc << "\n";
    }
    return 0;
}
