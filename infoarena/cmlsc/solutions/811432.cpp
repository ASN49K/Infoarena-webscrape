#include <fstream>
#define Nmax 1032
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m;
int a[Nmax],b[Nmax];
int lcs[Nmax][Nmax];
int op[Nmax][Nmax];

void citire();
void pd();
void afisare();
int maxim(int k,int l);

void citire(){
    int i,j;
    fin>>n>>m;
    for(i=0;i<n;i++)
        fin>>a[i];
    for(j=0;j<m;j++)
        fin>>b[j];
}
 
void pd(){
    int i,j;
    for(i=0;i<=n;i++)
        lcs[i][m]=0;
    for(j=0;j<=m;j++)
        lcs[n][j]=0;
    for(i=n-1;i>=0;i--)
        for(j=m-1;j>=0;j--)
            if(a[i]==b[j]){
                lcs[i][j]=1+lcs[i+1][j+1];
                op[i][j]=1;
            }
            else{
                lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
                if(lcs[i+1][j]>lcs[i][j+1])
                    op[i][j]=2;
                else
                    op[i][j]=3;
            }
}

int maxim(int k,int l){
    if(k>l)
        return k;
    return l;
}

void afisare(){
    int i,j;
    i=0;
    j=0;
    fout<<lcs[0][0]<<'\n';
    while(i<n &&j<m)
        if(op[i][j]==1){
            fout<<a[i]<<' ';
            i++;
            j++;
        }
        else{
            if(op[i][j]==3)
                j++;
            else
                i++;
        }
}
int main(){
    citire();
    pd();
    afisare();
    
    fout.close();
    return 0;
}
    