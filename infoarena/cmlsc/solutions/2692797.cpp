#include <iostream>
#include <fstream>

#define NMAX 1026
using namespace std;

int n,m;
int first[NMAX], second[NMAX];
int matchMatrix[NMAX][NMAX];

void read()
{
    scanf("%d %d\n", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d ", &first[i]);
    }
    scanf("\n");
    for(int i = 1; i <= m; i++){
        scanf("%d ", &second[i]);
    }
}

void createMatrix(){
    for(int i = 1 ; i <=n; i++)
        for(int j = 1;j<=m;j++){
            int match = first[i] == second[j];
            matchMatrix[i][j] = max(matchMatrix[i-1][j], max(matchMatrix[i][j-1],matchMatrix[i-1][j-1] + match));
        }
    printf("%d\n", matchMatrix[n][m]);
}

void solve(){
    int i = n,j=m, match;
    int length = 0, solution[NMAX];

    while(i && j){
        if(first[i] == second[j]){
            solution[length++] = first[i];
            i--; j--;
        }
        else if(matchMatrix[i-1][j] > matchMatrix[i][j-1])
            i--;
        else
            j--;
    }

    for(i = length -1; i >= 0 ; i--)
        printf("%d ", solution[i]);
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    read();
    createMatrix();
    solve();

    return 0;
}
