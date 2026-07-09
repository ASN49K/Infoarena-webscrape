#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,i,n;
void euclid(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    fout<<a<<'\n';
}
int main()
{
fin>>n;
for(i=1;i<=n;i++)
{
    fin>>a>>b;
    euclid(a,b);
}
    return 0;
}
