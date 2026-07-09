#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ifstream fin("cmlsc.in");

int N,M,k;
int a[1025],b[1025],c[1025];
int L[1025][1025];

void init(){
    for(int i = 0; i <= N; i++)
        L[i][0] = 0;
    for(int j = 1; j <= M; j++)
        L[0][j] = 0;
}

void construire(int i,int j){
    if(L[i][j] > 0){
        if(a[i] == b[j]){
            construire(i-1,j-1);
            k++;
            c[k] = a[i];
        }
        else{
            if(L[i-1][j] > L[i][j-1])
                construire(i-1,j);
            else
                construire(i,j-1);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> b[i];
    }
    init();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            if(a[i] == b[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j],L[i][j-1]);
        }
    }
    cout << L[N][M] << '\n';
    construire(N,M);
    for(int i = 1; i <= k; i++)
        cout << c[i] << " ";
    return 0;
}
/*
5 4
2 1 4 3 2
1 3 4 2
*/
