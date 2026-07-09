#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int maxx = 1 << 10 + 1;

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
    char * chr = new char [1<<8];
    for(int i=n,j=m; i!=0 || j!=0;)
    {
        if(c[i-1][j-1]==c[i][j]-1)
        {
            i--;
            j--;
            *(chr+len_ans)=char(a[i]+48);
            len_ans++;
            continue;
        }
        else
            if(c[i][j]==c[i-1][j] && c[i][j]==c[i][j-1] && c[i][j]==c[i-1][j-1])
            {
                i--;
                continue;
            }
         else
             if(c[i][j]!=c[i-1][j] && c[i][j]==c[i][j-1] && c[i][j]!=c[i-1][j-1])
             {
                 j--;
                 continue;
             }
    }

    fout<<c[n][m]<<"\n";

    for(int i=0;i<len_ans;i++)
        fout<<*(chr+len_ans-1-i)<<" ";

    return 0;

}
void bordare()
{
    for(int j=0;j<=m;j++)
        c[0][j]=0;
    for(int i=0;i<=n;i++)
        c[i][0]=0;
}