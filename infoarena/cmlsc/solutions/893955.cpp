#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max,m,n,x[1030],y[1030],lcs[1030][1030];

void rezolvare(){

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
                lcs[i][j]+=1+lcs[i-1][j-1];
            else if(lcs[i-1][j]>lcs[i][j-1])
                    lcs[i][j]=lcs[i-1][j];
            else lcs[i][j]=lcs[i][j-1];
        }

}

void afisare_max(int i,int j){

    if(lcs[i][j])
        {
            if(x[i]==y[j])
                afisare_max(i-1,j-1),fout<<x[i]<<" ";
            else
            {
                if(lcs[i][j]==lcs[i-1][j])
                    afisare_max(i-1,j);
                else if(lcs[i][j]==lcs[i][j-1])
                        afisare_max(i,j-1);

            }

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
    fout<<lcs[n][m]<<"\n";
    afisare_max(n,m);
    fout<<"\n";
    fin.close();
    fout.close();
    return 0;
}
