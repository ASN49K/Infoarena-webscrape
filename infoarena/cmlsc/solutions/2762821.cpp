#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int maxx = (1<<10)+1;

int n, m;
int a[maxx], b[maxx], c[maxx][maxx];
void bordare();

int main() {
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> a[i];

    for (int i = 0; i < m; i++)
        fin >> b[i];
/*
    for (int i = 0; i < n; i++)
        fout << a[i] << " ";
    fout << endl;
    for (int i = 0; i < m; i++)
        fout << b[i] << " ";
    fout << endl;
*/
    bordare();

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i-1]==b[j-1])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);

/*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
            fout<<c[i][j]<<" ";
        fout<<"\n";
    }
*/

    int i,j,len_ans=0;
    int ans[1<<8];
    for(int i=n,j=m;;)
    {
        if(i==0 || j==0)
            break;
        if(c[i-1][j-1]==c[i][j]-1 && c[i-1][j]==c[i][j]-1 && c[i][j-1]==c[i][j]-1)
        {
            i--;
            j--;
            ans[len_ans++]=a[i];
            continue;
        }
        else
            if(c[i][j]==c[i-1][j] && c[i][j]==c[i][j-1] && c[i][j]==c[i-1][j-1])
            {
                i--;
                continue;
            }
         else
             {
                 j--;
                 continue;
             }
    }

    fout<<c[n][m]<<"\n";


    for(len_ans--;len_ans>=0;len_ans--)
        fout<<ans[len_ans]<<" ";

    return 0;

}
void bordare()
{
    for(int j=0;j<=m;j++)
        c[0][j]=0;
    for(int i=0;i<=n;i++)
        c[i][0]=0;
}