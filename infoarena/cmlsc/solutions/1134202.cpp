#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int m, n, i, j, v1[1025], v2[1025], c[1025][1025], ord, sir[1025];

int main(){
    fin >> m >> n;
    for(i = 1; i <= m; i++)
        fin >> v1[i];
    for (i = 1; i <= n; i++)
        fin >> v2[i];
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            if (v1[i] == v2[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    fout << c[m][n] << '\n';
    i = m; j = n;
    while (i >= 1 and j >= 1)
        if(v1[i] == v2[j]){
            sir[++ord] = v1[i]; i--; j--;
        }
        else if (c[i - 1][j] < c[i][j - 1])
            j--;
        else
            i--;
    for (i = ord; i >= 1; i--)
        fout << sir[i] << " ";
    fout << '\n';
    fin.close();
    fout.close();
}

