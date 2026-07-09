#include <iostream>
#include <fstream>

using namespace std;

int m, n, a[1024], b[1024], d[1024][1024], sir[1024], k;
int maxim(int a, int b)
{
    if (a > b) return a;
    else return b;
}
int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> m >> n;
    for(int i = 1; i <= m; i++)
    {
        fin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        fin >>b[i];
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i] == b[j]){
                d[i][j] = 1 + d[i-1][j-1];
            }
            else{
                d[i][j] = maxim(d[i - 1][j], d[i][j - 1]);
            }
        }
    }

    k = 1;
    for (int i = m, j = n; i; ){
        if(a[i] == b[j]){
            sir[k++] = a[i];
            i--;
            j--;
        }
        else if (d[i][j - 1] > d[i-1][j]){
            j--;
        }
        else{
            i--;
        }

    }
    fout << k - 1 << "\n";
    for(int i = k - 1; i >= 1; i--){
        fout << sir[i] << " ";
    }
}
