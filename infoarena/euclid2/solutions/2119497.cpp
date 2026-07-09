#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int a,b,r;
int cmmdc(int a,int b)
{
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int i,n;
    fin >> n;
    for(i=0;i<n;i++)
    {
        fin>> a>> b;
        fout << cmmdc(a,b)<<'\n';
    }
}
