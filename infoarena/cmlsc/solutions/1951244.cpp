/*

*/
#include<fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short int n,m,v1[1030],v2[1030],x[1030][1030],sol[1030];

void citire()
{
    int i;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        fin>>v1[i];
    for(i=1;i<=m;i++)
        fin>>v2[i];
}

int main()
{
    int i,j,k=0;
    citire();


    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v1[i]==v2[j])
                x[i][j]=x[i-1][j-1]+1;
            else
                x[i][j]=max(x[i-1][j],x[i][j-1]);
            //fout<<x[i][j]<<" ";
        }
    //fout<<endl;
    }


    i=n;
    j=m;
    while(i&&j)
    {
        if(v1[i]==v2[j])
        {
            k++;
            sol[k]=v1[i];
            i--;
            j--;
        }
        else if(x[i][j-1]>=x[i-1][j])
            j--;
        else
            i--;
    }

    fout<<k<<'\n';
    for(;k>=1;k--)
        fout<<sol[k]<<' ';
    fout<<'\n';






    fin.close();
    fout.close();
    return 0;
}
