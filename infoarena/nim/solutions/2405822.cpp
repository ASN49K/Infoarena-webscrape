#include <fstream>

using namespace std;

ifstream fin("nim.in");
ofstream fout("nim.out");

int n,i,m,x,a,j;

int main()
{
    fin >> n;
    for (i=1;i<=n;i++)
    {
        fin >> m;
        fin >> x;
        for (j=2;j<=m;j++)
        {
            fin >> a;
            x=x^a;
        }
        if (m==1) fout << "DA";
        else
        {
            if (x==0) fout << "NU";
            else fout << "DA";
        }
        fout << "\n";
    }

    return 0;
}
