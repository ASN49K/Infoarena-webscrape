#include <fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmd(int a,int b)
{
    int c;
    while (b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int n,i,j;
    fin>>n;
    for (i=1;i<=n;i++)
    {
        int a,b;
        fin>>a>>b;
        fout<<cmmd(a,b)<<"\n";
    }
    return 0;
}
