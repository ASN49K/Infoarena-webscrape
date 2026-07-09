#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;
int cmmdc(int A, int B)
{
    int R;
    while (B)
        R=A%B, A=B, B=R;
    return A;
}
int main()
{
    int i;
    fin>>n;
    for (i=1;i<=n;++i)
        {
            fin>>a>>b;
            fout<<cmmdc(a,b)<<'\n';
        }
    return 0;
}
