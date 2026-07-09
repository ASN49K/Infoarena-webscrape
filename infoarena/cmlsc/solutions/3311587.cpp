#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int matrixDP[1025][1025];

int main(){

    int n, m;
    fin >> n >> m;

    int a[1024], b[1024];
    for(int i = 0; i < n; i++)
        fin >> a[i];

    for(int i = 0; i < m; i++)
        fin >> b[i];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1])
                matrixDP[i][j] = matrixDP[i - 1][j - 1] + 1;
            else
                matrixDP[i][j] = max(matrixDP[i-1][j], matrixDP[i][j-1]);
        }
    }

    stack<int> solutionStack;
    int indexRow = n;
    int indexCol = m;

    while(indexRow != 0 && indexCol != 0){
        int maximum = max(matrixDP[indexRow - 1][indexCol], matrixDP[indexRow][indexCol - 1]);
        if(maximum != matrixDP[indexRow][indexCol] && matrixDP[indexRow][indexCol] == matrixDP[indexRow - 1][indexCol - 1] + 1){
            indexRow--;
            indexCol--;
            solutionStack.push(a[indexRow]);
        }else{
            if(matrixDP[indexRow - 1][indexCol] > matrixDP[indexRow][indexCol - 1])
                indexRow--;
            else
                indexCol--;
        }
    }

    fout << solutionStack.size() << endl;
    while(!solutionStack.empty()){
        fout << solutionStack.top() << " ";
        solutionStack.pop();
    }

    return 0;
}


