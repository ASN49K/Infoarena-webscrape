#include<fstream>
#define NMAX 1024

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int n,m;
int a[NMAX],b[NMAX],mat[NMAX][NMAX],sir[NMAX],best;

void citire(){
    in>>n>>m;
    int i;
    for(i=1;i<=n;i++)
        in>>a[i];
    for(i=1;i<=m;i++)
        in>>b[i];
}

int mare(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}

void generare(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                mat[i][j]=1+mat[i-1][j-1];
            else
                mat[i][j]=mare(mat[i-1][j],mat[i][j-1]);
}

void sol(){
    int i,j;
    i=n;
    j=m;
    while(j>0){
        if(a[i] == b[j]){
            sir[++best]=a[i];
            i--;
            j--;
        }
        else
            if(mat[i-1][j] < mat[i][j-1])
                j--;
            else
                i--;
    }
}

void afis(){
    out<<best<<'\n';
    for(int i=best;i>0;i--)
        out<<sir[i]<<" ";
}

int main()
{
    citire();
    generare();
    sol();
    afis();
    return 0;
}
