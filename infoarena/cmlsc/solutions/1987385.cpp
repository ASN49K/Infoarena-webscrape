#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[260] ,b[260], x1[260], sol[260];
int n, m, nr = -1;
void citire()
{
    f >> m >> n;
    int i;
    for(i = 1; i <= m; i++)
        f >> a[i];
    for(i = 1; i <= n; i++)
        f >> b[i];
}
bool ok(int i)
{
    int j = 1, k = 1;
    while(j <= i and k <= n)
    {
        if(a[x1[j]] == b[k])
            j++;
        k++;
    }
    if(j == i + 1)
        return true;
    return false;
}
void bkt()
{
    int i = 1;
    while(i)
    {
        x1[i]++;
        if(x1[i] > m)
            i--;
        else
        {
            if(ok(i))
            if(i > nr)
                {nr = i;
            int v;
            for(v = 1; v <= i; v++)
                sol[v] = a[x1[v]];
            }

            i++;
            x1[i] = x1[i-1];
        }
    }
}
int main()
{
    citire();
    bkt();
    int s;
    g << nr << '\n';
    for(s = 1; s <= nr; s++)
        g << sol[s] << ' ';
    return 0;
}
