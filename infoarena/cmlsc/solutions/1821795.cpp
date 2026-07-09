#include <fstream>

using namespace std;

int main()
{
   ifstream f("cmlsc.in");
   ofstream g("cmlsc.out");

    int n,m,i,j,z;
    f >> n >> m;
    int M[n+1][m+1],K1[n+1],K2[m+1];
    M[0][0]=0;
    for(i=1;i<=n;i++){
        f>>K1[i];
        M[i][0]=0;
    }
    for(i=1;i<=m;i++){
        f>>K2[i];
        M[0][i]=0;
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++){
        if(K1[i]==K2[j])M[i][j]=M[i-1][j-1]+1;
        else
        M[i][j]=max(M[i-1][j-1],max(M[i-1][j],M[i][j-1]));
    }

    bool k=0;
    int ij[2];
    ij[0]=n;ij[1]=m;z=1;
    while(ij[0]!=0&&ij[1]!=0){
        if(K1[ij[0]]==K2[ij[1]]){M[0][z]=K1[ij[0]];z++;ij[0]--;ij[1]--;}
        else{
            if(M[ij[k]-1][ij[k]]==M[ij[k]][ij[k]])ij[k]--;
            if(M[ij[k]][ij[k]-1]==M[ij[k]][ij[k]])ij[k]--;
            k=!k;

            }
    }

    g << z-1 << '\n';
    for(i=z-1;i>=1;i--)
        g<< M[0][i] << " ";


    f.close();
    g.close();
    return 0;
}
