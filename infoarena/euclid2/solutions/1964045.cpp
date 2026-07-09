#include <fstream>

using namespace std;

ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");

int euclid(int a,int b)
{
    int r;
    while(b!=0)
        r=a%b,a=b,b=r;
    return a;
}

int main()
{
    int n,i,nr,nr1;
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> nr >> nr1;
        fout << euclid(nr,nr1) << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
