#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


ifstream fi;
ofstream fo;
int m,n;
int A[1024];
int B[1024];
int sol[1024][1024];
int merge[1024][1024];
int max;
int bla[1024];

int maxim(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    fi.open ("cmlsc.in");
    fi >> m >> n;
    for (int i=1; i<=m; i++)
        fi >> A[i];
    for (int i=1; i<=n; i++)
        fi >> B[i];
    fi.close();
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
        {
            sol[i][j] = 0;
            merge[i][j] = 0;
        }
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            {
                if (A[i] == B[j])
                {
                    sol[i][j] = sol[i-1][j-1] + 1;
                    merge[i][j] = 1;
                }
                else
                {
                    if (sol[i-1][j] >= sol[i][j-1])
                    {
                        merge[i][j] = 2;
                        sol[i][j] = sol[i-1][j];
                    }
                    else
                    {
                        merge[i][j] = 3;
                        sol[i][j] = sol[i][j-1];
                    }
                }
                //tiparire();
                //system("PAUSE");
                //cout << endl;
            }
    fo.open("cmlsc.out");
    fo << sol[m][n] << endl;

    int i = m;
    int j = n;
    int k = sol[m][n];
    int k2 = k;
    while (true)
    {
        if (merge[i][j] == 1)
        {
            bla[k2] = A[i];
            --i;
            --j;
            --k2;
        }
        else
        if (merge[i][j] == 2)
            --i;
        else
            --j;
        if (k2 == 0)
            break;
    }
    for (i=1; i<=k; i++)
        fo << bla[i] << " ";
    fo.close();
    return 0;
}
