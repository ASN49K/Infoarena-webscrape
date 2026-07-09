#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max,m,n,nou[1030],nr,x[1030],y[1030],lcs[1030][1030];

void rezolvare(){

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                lcs[i][j]+=1+lcs[i-1][j-1];
            else if(lcs[i-1][j]>lcs[i][j-1])
                    lcs[i][j]=lcs[i-1][j];
            else lcs[i][j]=lcs[i][j-1];
        }

}



int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int j=1;j<=m;j++)
        fin>>y[j];
    rezolvare();
    for(int i=n,j=m;i; )
        if(x[i]==y[j])
            nou[++nr]=x[i], i--, j--;
        else if(lcs[i-1][j]<lcs[i][j-1])
                j--;
        else i--;
    fout<<nr<<"\n";
    for(int i=nr;i>=1;i--)
        fout<<nou[i]<<" ";
    fout<<"\n";
    fin.close();
    fout.close();
    return 0;
}
