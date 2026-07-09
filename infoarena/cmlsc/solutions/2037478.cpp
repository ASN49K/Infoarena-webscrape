#include <fstream>
using namespace std;

ifstream fin("scmax.in");
ofstream fout("scmax.out");

const int MaxN = 100001, Inf = 0x3f3f3f3f;
int a[MaxN];    // asta se citeste
int v[MaxN];    // e un sir crescator in care se cauta
                // binar pozitia pe care trebuie plasat fiecare
                // element a[i]
int p[MaxN];    // p[i] = pozitia in sirul v pe care se plaseaza a[i]
int sol[MaxN];  // retine UNUL dintre subsirurile maximale (in ordine inversa)
int n;
int Lmax;       // lungimea CMLSC

void ReadArray();
void Sclm();
int BinarySearch(int val);
void WriteSolution();

int main()
{
    v[0] = -Inf;
    ReadArray();
    Sclm();
    WriteSolution();
}

int BinarySearch(int val)
{
    if (val > v[Lmax])
        return Lmax + 1;
    int l = 1, r = Lmax, m, poz = 1;

    while (l <= r)
    {
        m = (l + r) / 2;
        if (val <= v[m])
        {
            poz = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    return poz;
}

void Sclm()
{
    for (int i = 1; i <= n; ++i) // O(n * log n)
    {
        int poz = BinarySearch(a[i]);
        v[poz] = a[i];
        p[i] = poz;
        if (poz > Lmax)
            Lmax = poz;
    }
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






