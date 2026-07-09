#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int maxim(int a, int b)
{
    if(a>b) return a;
    return b;
}
int M, N, A[1024], B[1024], D[1024][1024],sir[1024],bst;
int main()
{

    int i, j;
    f>>M>>N;
    for(i=1;i<=M;i++)
        f>>A[i];
    for(i=1;i<=N;i++)
        f>>B[i];
    for(i=1;i<=M;i++)
        for(j=1;j<=N;j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
    /*for(i=1;i<=M;i++)
    {
        for(j=1;j<=N;j++)
            g<<D[i][j]<<" ";
        g<<endl;
    }*/
     for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;

    g<<bst<<endl;
    for (i = bst; i; --i)
        g<<sir[i]<<" ";
    return 0;
}
