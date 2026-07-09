#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

int d[1100][1100];

void backtrack(int a[], int b[], vector<int> &subseq, int i, int j)
{
    if(i == 0 || j == 0){
        return;
    }
    if(a[i-1] == b[j-1]){
        subseq.push_back(a[i-1]);
        backtrack(a, b, subseq, i-1, j-1);
    }
    if(d[i][j-1] > d[i-1][j]){
        backtrack(a, b, subseq, i, j-1);
    }
    else{
        backtrack(a, b, subseq, i-1, j);
    }
    return;
}


int main()
{
    int a[1025], b[1025];
    int M, N;
    input >> M >> N;
    for(int i = 0; i < M; i++){
        input >> a[i];
    }
    for(int i = 0; i < N; i++){
        input >> b[i];
    }

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(a[i-1] == b[j-1]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else{
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    vector<int> subseq;
    backtrack(a, b, subseq, M, N);
    output << d[M][N] << endl;
    for(int i = d[M][N] - 1; i >= 0; i--){
        output << subseq[i] << " ";
    }
    return 0;
}
