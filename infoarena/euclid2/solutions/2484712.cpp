#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,n,i;

int euclid(int x, int y)
{
    int c;
    a=x>=y?x:y;
    b=y<=x?y:x;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<"\n";
    }
    return 0;
}
