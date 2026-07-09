#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1024], b[1024], vf, maxim = -1000, poz;

struct cmlsc{
    int x, y;

};

cmlsc c[1024];

bool Valid(int k)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == k)
            return true;
    }

    return false;
}

void Afis(int i)
{
    fout << b[i] << " ";
    if(c[i].y)
        Afis(c[i].y);
}
int main()
{
        fin >> n >> m;
        for(int i = 1; i <= n; i++)
            fin >> a[i];

        for(int i = 1; i <= m; i++)
        {
            int k;
            fin >> k;
            if(Valid(k))
                b[++vf] = k;
        }

        c[vf].x = 1;
       for(int i = vf - 1; i > 0; i--)
       {
           c[i].x = 1;
           for(int j = i + 1; j <= vf; j++)
            if(b[i] < b[j] && c[i].x - 1 < c[j].x)
           {

               c[i].x = c[j].x + 1;
               c[i].y = j;


           }

            if(c[i].x > maxim)
            {
                maxim = c[i].x;
                poz = i;
            }
       }
       fout << maxim << '\n';
        Afis(poz);

    fout << '\n' << (sizeof(a)+sizeof(b)+sizeof(c));
    return 0;
}
