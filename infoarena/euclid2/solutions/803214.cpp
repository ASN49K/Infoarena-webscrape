#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,m[3][100005];
int cmmdc(int t1, int t2)
{
    while(t2){ int c=t1%t2; t1=t2; t2=c;}
    return t1;
}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        {
            f>>m[1][i]>>m[2][i];
            g<<cmmdc(m[1][i],m[2][i])<<'\n';
        }
    return 0;
}

