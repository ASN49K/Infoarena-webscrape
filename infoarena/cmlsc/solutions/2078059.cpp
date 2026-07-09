#include <iostream>
#include <fstream>

using namespace std;

const int nm = 1024;

int x[nm+2][nm+2];
int a[nm+2],b[nm+2],er[nm+2];
int n, m;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main()
{
    fin >> n >> m;
    for(int i = 1 ; i <= n; ++i)
        fin >> a[i];
    for(int i = 1 ; i <= m; ++i)
        fin >> b[i];

    /*for(int j = 1; j <= m; ++j)
    {
        x[0][j] = b[j-1];
    }
    for(int j = 1; j <= n; ++j)
    {
        x[j][0] = a[j-1];
    }*/

    for(int i = 1 ; i <= n; ++i)
    {

        for(int j = 1; j <=m; ++j)
        {

            if(a[i] == b[j])
            {

                x[i][j] = x[i-1][j-1] + 1;


            }
            else
            {
                x[i][j] = max(x[i-1][j],x[i][j-1]);
            }
        }
    }

    /*for(int i = 1 ; i <= n; ++i)
    {
        for(int j = 1 ; j <= m; ++j)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }*/
    int i = n;
    int j = m;
    int k = 0;
    while(x[i][j])
    {
        while(x[i][j-1] == x[i][j])
            --j;
        while(x[i-1][j] == x[i][j])
            --i;

        er[k] = a[i];
        //cout << i << " " << j << endl;
        //cout << a[i];
        ++k;
        --i; --j;
    }


    fout << k <<"\n";
    for(int i = k-1; i >= 0; --i)
    {
        fout << er[i] << " ";
    }

    return 0;
}
