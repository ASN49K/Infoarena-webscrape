#include <fstream>
#define ll long long
using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

ll r,nr,nr1;

int euclid(ll nr,ll nr1)
{
    while(nr1!=0)
        r=nr%nr1,nr=nr1,nr1=r;
    return nr;
}

int main()
{
    int n,i;
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> nr >> nr1;
        euclid(nr,nr1);
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
