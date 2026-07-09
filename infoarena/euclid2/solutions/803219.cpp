#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,m1,m2;
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
            f>>m1>>m2;
            g<<cmmdc(m1,m2)<<'\n';
        }
    return 0;
}

