#include <iostream>

#include <fstream>

#define nmax 1030



using namespace std;



//ifstream fin("date.in");
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");



int n, m, a[nmax], b[nmax], d[nmax][nmax], s[nmax], k;



void read(){

    fin >> n >> m;

    for(int i = 0; i < n; ++i)

        fin >> a[i];

    for(int i = 0; i < m; ++i)

        fin >> b[i];

}



void solve(){

    for(int i = 0; i <= n; ++i)

        d[i][0] = d[0][i] = 0;

    for(int i = 1; i <= n; ++i)

        for(int j = 1; j <= m; ++j)

            if(a[i - 1] == b[j - 1])

                d[i][j] = d[i - 1][j - 1] + 1;

            else

                d[i][j] = max(d[i - 1][j], d[i][j - 1]);

}



void sol(){

    cout << d[n][m] << endl;

    for(int i = n; i >= 1; --i){

        for(int j = m; j >= 1; --j)

            if(d[i][j] == d[i - 1][j] && d[i][j] != d[i][j - 1]){

                i--;

            }

            else if(d[i][j] == d[i][j - 1] && d[i][j] != d[i - 1][j]){

                j--;

            }

            else if(d[i][j] == d[i][j - 1] && d[i][j] == d[i - 1][j]){

                j--;

            }

            else

                s[k++] = a[i - 1];

        }

    for(int i = k - 1; i >= 0; --i)

        cout << s[i] << " ";

}



int main()

{

    read();

    solve();

    sol();

    return 0;

}
