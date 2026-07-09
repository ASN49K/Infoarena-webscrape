#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],mat[1025][1025],lgt;
int sol[1025];

void calculate_matrix(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i]==b[j]){
                mat[i][j]=mat[i-1][j-1]+1;
            }
            else{
                mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
            }
        }
    }
}

void complete_solution_array(){
    int i=n;
    int j=m;
    int poz=1;
    while(i>=1&&j>=1){
        while(mat[i][j]==mat[i-1][j]){
            i--;
        }
        while(mat[i][j]==mat[i][j-1]){
            j--;
        }
        sol[poz]=a[i];
        i--;
        j--;
        poz++;
    }
}

int main(){
    f>>n>>m;
    for(int i=1;i<=n;i++){
        f>>a[i];
    }
    for(int i=1;i<=m;i++){
        f>>b[i];
    }
    calculate_matrix();
    g<<mat[n][m]<<"\n";
    complete_solution_array();
    for(int i=mat[n][m];i>=1;i--){
        g<<sol[i]<<" ";
    }
    return 0;
}
