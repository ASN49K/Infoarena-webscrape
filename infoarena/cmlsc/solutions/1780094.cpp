#include<cmath>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, ct, l[1025], d[1025][1025], a[1025], b[1025];

int main(){

    fin >> m >> n;

    for(int i = 1;i <= m;++i)
        fin >> a[i];

    for(int i = 1;i <= n;++i)
        fin >> b[i];

    for(int i = 1;i <= m;++i){

        for(int j = 1;j <= n;++j){

            if(a[i] == b[j]){

                d[i][j] = 1 + d[i-1][j-1];
            }
            else{

                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }

    fout << d[m][n] << endl;

    for(int i = m,j = n;i;){

        if(a[i] == b[j])
            l[++ct] = a[i],--i,--j;
        else if(d[i-1][j] < d[i][j-1])
            --j;
        else
            --i;
    }

    for(int i = ct;i > 0;--i)
        fout << l[i] << " ";

    return 0;
}
