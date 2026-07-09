#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], c[1025][1025], sir[1025], cnt = 0; 

int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; ++i)
        fin >> a[i];

    for(int i = 1; i <= m; ++i)
        fin >> b[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(a[i] == b[j])
                c[i][j] = 1 + c[i-1][j-1];
            else
            {
                if(c[i-1][j] > c[i][j-1]) 
                    c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }

    for(int i = n, j = m; i; )
        if(a[i] == b[j])
            sir[++cnt] = a[i], i--, j--;
        else if(c[i-1][j] < c[i][j-1])
            --j;
        else
            --i;

    fout << cnt << endl;
    for(int i = cnt; i; --i)
        fout << sir[i] << " ";

    return 0;
}