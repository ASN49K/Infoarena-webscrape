
 #include <fstream>
using namespace std;
#define maxn 1025
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int a[maxn],b[maxn],mat[maxn][maxn], v[maxn],l=0;


void lcs(int m, int n){
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++){
            if(a[i]==b[j]){
                v[0]++;
                mat[i][j]=mat[i-1][j-1]+1;
                }
            else
                mat[i][j]=max(mat[i][j-1], mat[i-1][j]);
        }
}
void afisarelcs(int m, int n){
    for(int i=m,j=n; i && j; )
        if(a[i]==b[j]) v[++l]=a[i],--i,--j;
        else if(mat[i-1][j] < mat[i][j-1]) --j;
        else --i;
    cout<<v[0]<<'\n';
    for(int i=l; i; i--) cout<<v[i]<<' ';
}
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        cin>>b[i];
    lcs(m,n);
    afisarelcs(m,n);
    return 0;
}

