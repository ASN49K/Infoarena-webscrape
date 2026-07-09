#include<fstream>
using namespace std;
// declarations
const int LEN = 1025;
int N,M,a[LEN],b[LEN], mat[LEN][LEN],sol[LEN];

int check(int x, int y){
    return (x > y) ? x : y;
}
int cmlsc(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i-1] == b[j-1]){
                mat[i][j] = mat[i-1][j-1]+1;
            }
            else mat[i][j] = check(mat[i][j-1], mat[i-1][j]);
        }
    }
    return mat[N][M];
}
int main()
{
    int i,j;
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> N >> M;
    for(i = 0; i < N; i++){
        fin >> a[i];
        mat[i][0] = 0;
    }
    mat[N][0] = 0;
    for(i = 0; i < M; i++){
        fin >> b[i];
        mat[0][i] = 0;
    }
    mat[0][M] = 0;
    fout << cmlsc()<<"\n";
    for(i = 1, j = 1; j <= M && i <= N;){
        if(a[i-1] == b[j-1]){
            fout << a[i-1] << " ";
            i++;
            j++;
        }
        else if (mat[i-1][j] < mat[i][j-1])
            j--;
        else
            i++;
    }
    fout <<"\n";
    fin.close();
    fout.close();
    return 0;
}
