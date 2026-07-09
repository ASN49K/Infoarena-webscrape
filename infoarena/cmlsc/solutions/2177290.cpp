#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], c[1025], fr[1025], k, maxim = -110020, poz, n, m;

struct dinamica{
    int x, y;

};

dinamica d[1025];

void Afis(int k)
{
    fout << c[k] << " ";

    if(d[k].y)
        Afis(d[k].y);
}

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
        fr[a[i]]++;
    }
    for(int i = 1; i <= m; i++)
    {
        fin >> b[i];
        if(fr[b[i]])
            c[k++] = b[i];

    }

    d[k-1].x = 1;

    for(int i = k-2; i >= 0; i--)
    {
        d[i].x = 1;
        for(int j = i + 1; j < k ; j++)
        {
            if(c[i] < c[j] && d[i].x -1 < d[j].x)
            {
                d[i].x = d[j].x + 1;
                d[i].y = j;
            }

        }
        if(d[i].x > maxim)
        {
            maxim = d[i].x;
            poz = i;
        }

    }

    fout << maxim << '\n';
    Afis(poz);



    return 0;
}
