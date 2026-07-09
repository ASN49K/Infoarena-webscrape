#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030], b[1030], l[1030][1030], s[1030], loc;

int main(){
    int i, j, m, n;
    fin >> m >> n;
    for (i = 1;i <= m;i++)
        fin >> a[i];
    for (i = 1;i <= n;i++)
        fin >> b[i];
    for (i = 1;i <= m;i++)
        for (j = 1;j <= n;j++)
            if (a[i] == b[j])
                l[i][j] = 1 + l[i-1][j-1];
            else
                l[i][j] = max(l[i-1][j], l[i][j-1]);
    i = m;
    j = n;
    while (i){
        if (a[i] == b[j])
            s[++loc] = a[i], --i, --j;
        else if (l[i-1][j] < l[i][j-1])
            --j;
        else
            --i;
    }
    fout << loc << '\n';
    for (i = loc;i > 0;i--)
        fout << s[i] << " ";
    return 0;
}

