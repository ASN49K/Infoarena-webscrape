#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,k;
int a[1025],b[1025],c[1025];
int l[1025][1025];

void init(){
    for(int i=0;i<=n;i++)
        l[i][0]=0;
    for(int j=1;j<=m;j++)
        l[0][j]=0;
}

void constr(int i,int j){
    if(l[i][j] > 0){
        if(a[i] == b[j]){
            constr(i-1,j-1);
            k++;
            c[k] = a[i];
        }
        else{
            if(l[i-1][j] > l[i][j-1])
                constr(i-1,j);
            else
                constr(i,j-1);
        }
    }
}

int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(int i = 1; i <= m; i++){
        fin >> b[i];
    }
    init();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    }
    fout << l[n][m] << '\n';
    constr(n,m);
    for(int i = 1; i <= k; i++)
        fout << c[i] << " ";
    return 0;
}
