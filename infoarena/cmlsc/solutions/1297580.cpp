#include <fstream>
#include <vector>

typedef unsigned short uS_t;

int main(){
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");

    uS_t m,n;
    fin>>m>>n;

    std::vector<uS_t> a(m+1),b(n+1);
    for(uS_t i=1;i<=m;++i) fin>>a[i];
    for(uS_t j=1;j<=n;++j) fin>>b[j];

    std::vector< std::vector<uS_t> > lcs(m+1,std::vector<uS_t>(n+1));
    for(uS_t i=0;i<=m;++i) lcs[i][0]=0;
    for(uS_t j=0;j<=n;++j) lcs[0][j]=0;

    for(uS_t i=1;i<=m;++i)
        for(uS_t j=1;j<=n;++j)
            if(a[i]==b[j])
                lcs[i][j]=lcs[i-1][j-1]+1;

            else if(lcs[i-1][j]>lcs[i][j-1])
                lcs[i][j]=lcs[i-1][j];

            else
                lcs[i][j]=lcs[i][j-1];


    uS_t bst=lcs[m][n];
    fout<<bst<<'\n';

    std::vector<uS_t> v(bst+1);
    uS_t i=m, j=n;

    while(bst){
        if(a[i]==b[j]){
            v[bst--]=a[i]; --i; --j;
        }
        else if(lcs[i-1][j]>lcs[i][j-1]) --i;
        else --j;
    }

    for(i=1;i<v.size();++i) fout<<v[i]<<' ';
    fout<<'\n';
}
