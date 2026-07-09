#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int n,i,eu,a,b;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        eu=euclid(a,b);
        fout<<eu<<'\n';
    }
    return 0;
}
