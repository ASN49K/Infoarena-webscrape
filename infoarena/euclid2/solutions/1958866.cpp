#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int r,nr,nr1;

void euclid()
{
    while(nr1!=0)
        r=nr%nr1,nr=nr1,nr1=r;
}

int main()
{
    int n,i;
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> nr >> nr1;
        euclid();
        fout << nr << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
