#include <fstream>
using namespace std;

#define SQ(i) ((i)*(i))
#define PW(i) (1<<(i))
#define min(a,b) ((a) < (b) ? (a) : (b))
#define M 10000

struct vector
{
    int a, b;
}v[30], y[30];

int T, A, B, i, j, k1, k2, rez = 1;

int fact(int N, vector v[])
{
    memset(v,0,sizeof(v));
    int k = 0;
    for (i = 2; SQ(i) <= N; i++)
        if (N % i == 0)
        {
            v[++k].a = 0;
            v[k].b = i;
            while (N % i == 0)
            {
                ++v[k].a;
                N /= i;
            }
        }
    if (N != 1)
        v[++k].a = 1, v[k].b = N;
    return k;
}
int lgput(int a,int p)
{
    int sol = 1, i;
    for (i = 0; PW(i) <= p; i++)
    {
        if ( (PW(i) & p) > 0)
            sol = (sol * a) % M;

        a = SQ(a) % M;
    }
    return sol;
}
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f >> T;
    while (T--)
    {
        f >> A >> B;
        k1 = fact(A,v), k2 = fact(B,y);
        rez = 1;
        if (v[1].a > y[1].a)
        {

            for (i = 1, j = 1; i <= k1; i++)
                for ( j = 1; v[i].b >= y[j].b && j <= k2 ; j++)
                {
                    if (v[i].b == y[j].b && v[i].b && y[j].b)
                        rez *= lgput(v[i].b,min(v[i].a,y[j].a));
                }
        }
        else
        {
            for (i = 1, j = 1; i <= k2; i++)
                for ( ; y[i].b >= v[j].b && j <= k1 ; j++)
                {
                    if (y[i].b == v[j].b && y[i].b && v[j].b)
                        rez *= lgput(y[i].b,min(y[i].a,v[j].a));
                }
        }
        g << rez << "\n";
    }

    return 0;
}
