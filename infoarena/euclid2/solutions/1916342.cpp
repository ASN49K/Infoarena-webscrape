#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int x,y,i,n;
int euclid(int a,int b)
{
    int c;
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
        fin>>x>>y;
        fout<<euclid(x,y)<<"\n";
    }
    return 0;
}
