#include<algorithm>
#include<fstream>
using namespace std;

int m,n,ct,i,j,ofya[1025],d[1025][1025],a[1025],b[1025];

int main(){

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    scanf("%d%d", &m, &n);

    for(i=1;i<=m;++i){

        fin>>a[i];
    }

    for(i=1;i<=n;++i){

        fin>>b[i];
    }

    for(i=1;i<=m;++i){

        for(j=1;j<=n;++j){

            if(a[i]==b[j]){

                d[i][j]=1+d[i-1][j-1];
            }
            else{

                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }

    fout<<d[m][n];

    for(i=m;j=n;i){

        if(a[i]==b[j]){
            ofya[++ct]=a[i];--i;--j;}
        else if(d[i-1][j]<d[i][j-1])
            --j;
        else
            --i;
    }

    for(int i=ct;i>0;--i){

        fout<<ofya[i]<<" ";
    }
}
