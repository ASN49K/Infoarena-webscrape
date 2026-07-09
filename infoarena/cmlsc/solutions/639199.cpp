#include <fstream>

using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int d[1030][1030],a[1030],b[1030],M,N;

int max (int a, int b)
{
    if (a<=b)
        return b;
    else return a;
}

void refac (int lin, int col)
{
    if (lin == 0 || col == 0) return;
    if (a[lin] == b[col])
    {
        refac (lin-1, col-1);
        out<<a[lin]<<" ";
        return;
    }
    if (d[lin-1][col]>d[lin][col-1])
        refac (lin-1,col);
    else refac (lin,col-1);
}

int main ()
{
    in>>M>>N;
    for (int i=1 ; i<=M ; i++)
    {
        in>>a[i];
    }
    for (int i=1 ; i<=N ; i++)
    {
        in>>b[i];
    }
    for (int i=1 ; i<=M ; i++)
    {
        for (int j=1 ; j<=N ; j++)
        {
            if (a[i] == b[j])
                d[i][j] = d[i-1][j-1]+1;
            else d[i][j] = max (d[i-1][j] , d[i][j-1]);
        }
    }
    out<< d[M][N]<<"\n";
    refac (M,N);
}



