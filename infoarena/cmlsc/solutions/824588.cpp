#include<cstring>
#include<fstream>
using namespace std;
ifstream f("cmlsc.in"); ofstream g("cmlsc.out");
char s1[1050], s2[1050], best [1050];
int d[1050][1050], lgmax, n,m;
int main(){
    f>>s1>>s2;
    n=strlen(s1); m=strlen(s2);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(s1[i-1]==s2[j-1]) d[i][j]=d[i-1][j-1]+1; //nu se modifica nimic
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
    for(int i=n,j=m; i>=1;)
        if(s1[i]==s2[j])
            best[++lgmax]=s1[i],--i,--j;
        else
            if(d[i-1][j]<d[i][j-1]) --j;
            else --i;
    g<<lgmax<<'\n';
    for( int i=lgmax; i>=1; --i) g<<best[i];
    g<<'\n'; g.close(); return 0;
}
