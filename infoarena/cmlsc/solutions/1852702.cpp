#include <fstream>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int s1[1030];
int s2[1030];
int rasp[1030][1030];
int afis[1030];



int main()
{
    int n,m;
    fin >> n >> m;
    for (int i=1;i<=n;i++) fin >> s1[i];
    for (int i=1;i<=m;i++) fin >> s2[i];

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {

            if (s1[i]==s2[j]) rasp[i][j]=rasp[i-1][j-1]+1;
            else
            {
                rasp[i][j]=max(rasp[i][j],rasp[i-1][j]);
                rasp[i][j]=max(rasp[i][j],rasp[i][j-1]);
            }

        }
    fout << rasp[n][m] << "\n";
    int indice=0;
    for (int i=n,j=m;i>=1;)
    {
        if (s1[i]==s2[j])
        {
            afis[++indice] = s1[i];
            i--;
            j--;
        }
        else if (rasp[i-1][j]<rasp[i][j-1]) j--;
        else i--;
    }
    for (int i=indice;i>=1;i--) fout << afis[i] << " ";


    return 0;
}
