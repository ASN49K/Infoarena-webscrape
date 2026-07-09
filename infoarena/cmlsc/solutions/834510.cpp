#include <fstream>
#include <vector>

int main(){
    std::ifstream fin("cmlsc.in");
    std::ofstream fout("cmlsc.out");
    unsigned short n,m;
    fin>>m>>n;
    std::vector<unsigned short> a(m), b(n);
    for(unsigned short i=0;i<m;++i) fin>>a[i];
    for(unsigned short i=0;i<n;++i) fin>>b[i];

    std::vector< std::vector<unsigned short> > lcs(m,std::vector<unsigned short>(n));
    if(a[0]==b[0]) lcs[0][0]=1; else lcs[0][0]=0;
    for(unsigned short i=1;i<m;++i) if(b[0]==a[i]) lcs[i][0]=1; else lcs[i][0]=lcs[i-1][0];
    for(unsigned short i=1;i<n;++i) if(a[0]==b[i]) lcs[0][i]=1; else lcs[0][i]=lcs[0][i-1];
    for(unsigned short i=1;i<m;++i)
        for(unsigned short j=1;j<n;++j)
            if(a[i]==b[j]) lcs[i][j]=lcs[i-1][j-1]+1;
            else lcs[i][j]=(lcs[i-1][j]>lcs[i][j-1]?lcs[i-1][j]:lcs[i][j-1]);
    std::vector<unsigned short> rseq(lcs[m-1][n-1]);
    int pos=0; unsigned short i=m-1,j=n-1;
    while(pos<lcs[m-1][n-1]){
        if(a[i]==b[j]){ rseq[pos++]=a[i]; --i; --j; }
        else if(j==0) --i;
        else if(i==0||lcs[i][j-1]>lcs[i-1][j]) --j;
        else --i;
    }
    fout<<lcs[m-1][n-1]<<'\n';
    for(pos--;pos>=0;--pos) fout<<rseq[pos]<<' ';
    fout<<'\n';
}
