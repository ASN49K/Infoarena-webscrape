#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream input("cmlsc.in");
ofstream output("cmlsc.out");

int d[1025][1025] = {};
vector<int> a, b;

int main()
{
    int M, N;
    for(int i = 0; i < M; i++){
        int x;
        input >> x;
        a.push_back(x);
    }
    for(int i = 0; i < N; i++){
        int x;
        input >> x;
        b.push_back(x);
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(a[i] == b[i]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else{
                d[i][j] = max(d[i-1][j], d[i][j-1]);
            }
        }
    }
    output << d[M][N];
    return 0;
}
