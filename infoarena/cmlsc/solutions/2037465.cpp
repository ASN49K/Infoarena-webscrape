#include <fstream>
using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

const int MaxN = 100001;
int a[MaxN];
int v[MaxN];

int p[MaxN];
int L[MaxN];
int R[MaxN];
int sol[MaxN];

int n;
int Lmax;

void ReadArray();
void WriteSolution();
int CautareBinara(int val);
void Sclm(int x);

int main()
{
    v[0] = -0x3f3f3f;
    ReadArray();
    Sclm(L);
    Sclm(R);
    WriteSolution();
}
void ReadArray()
{
    fin >> n;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
}

void WriteSolution()
{
    fout << Lmax << '\n';
    int k = Lmax, j = 0;
    for (int i = n; i >= 1; --i)
        if (p[i] == k)
        {
            sol[++j] = a[i];
            k--;
        }

    for (int i = Lmax; i >= 1; --i)
        fout << sol[i] << ' ';
}
int CautareBinara(int val)
{
    if (val > v[Lmax])
        return Lmax + 1;
    int l = 1, r = Lmax, m, poz = 1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (val < v[m])
        {
            r = m - 1;
            poz = m;
        }
        else
            l = m + 1;
    }

    return poz;
}
void Sclm()
{
    for (int i = 1; i <= n; ++i)
    {
        int poz1 = CautareBinara(a[i]);
        v[poz1] = a[i];
        L[i] = poz1;
        //if ( poz1 > Lmax )
            //Lmax = poz1;
    }
    for ( int i = MaxN; i >= 1; --i)
    {
        int poz2 = CautareBinara(a[i]);
        v[poz2] = a[i];
        R[i] = poz2;
        //if ( poz2 )
    }
}
