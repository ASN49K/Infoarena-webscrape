#include <iostream>
#include <fstream>
using namespace std;


int** LCS_length(int* a,int N, int* b, int M)
{
    int n = N+1;
    int m = M+1;
    int** c = new int*[n+1];
    for(int i=0; i<n;i++)
        c[i] = new int[m];

    for(int i=0; i<n;i++)
        c[i][0] = 0;
    for(int i=0; i<m;i++)
        c[0][i] =0;
    for(int i=1; i<n;i++)
        for(int j=1; j<m;j++)
            if(a[i-1] == b[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = c[i][j-1] > c[i-1][j] ? c[i][j-1] : c[i-1][j];
    return c;
}

int* getValues(int**c, int* a, int* b, int n, int m, int *k)
{

    *k=0;
    int *s = new int[c[n][m]];
    for(int i=n, j=m; i>0 && j>0;)
        if(a[i-1] == b[j-1])
        {
            s[(*k)++] = a[i-1];
            i--;
            j--;
        }
        else if(c[i-1][j] < c[i][j-1])
            j--;
        else
            i--;
    return s;
}

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

    int m,n;
     in >> n >> m;

    int *a = new int[n];
    int *b = new int[m];

    for(int i = 0 ; i < n; i++)
        in >> a[i];
    for(int i = 0 ; i < m; i++)
        in >> b[i];

    int **c = LCS_length(a,n,b,m);
    int k=0;
    int *s = getValues(c,a,b,n,m,&k);
    out << k << endl;
    for(int i=k-1;i>=0;i--)
        out<<s[i]<<" ";

    return 0;
}
