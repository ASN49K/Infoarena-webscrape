# include <fstream>
# define DIM 1044
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int v[DIM][DIM],a[DIM],b[DIM],sol[DIM],nr1,nr2,i,j,k;
int main () {
    fin>>nr1>>nr2;
    for(i=1;i<=nr1;i++)
        fin>>a[i];
    for(i=1;i<=nr2;i++)
        fin>>b[i];
    for(i=1;i<=nr1;i++){
        for(j=1;j<=nr2;j++){
            if(a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    }
    fout<<v[nr1][nr2]<<"\n";
    i=nr1;
    j=nr2;
    while(k!=v[nr1][nr2]){
        if(a[i]==b[j]){
            sol[++k]=a[i];
            i--;
            j--;
        }
        else{
            if(v[i-1][j]>v[i][j-1])
                i--;
            else
                j--;
        }
    }
    for(i=k;i>=1;i--)
        fout<<sol[i]<<" ";
    fout<<"\n";
    return 0;
}
