#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int main()
{
    int n,i,nr,nr1,r;
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> nr >> nr1;
        r=1;
        while(r!=0)
        r=nr%nr1,nr=nr1,nr1=r;
        fout << nr << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
