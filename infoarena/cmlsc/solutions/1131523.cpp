#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int NMAX = 1030;

int N; int M; int B[NMAX]; int A[NMAX]; int Best[NMAX][NMAX]; int Last[NMAX][NMAX];

vector<int> Solution;

int main() {

    fin >> N >> M;
    for(int i = 1; i <= N; ++i)
        fin >> A[i];
    for(int i = 1; i <= M; ++i)
        fin >> B[i];

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j) {
            if(A[i] == B[j]) {
                Best[i][j] = Best[i - 1][j - 1] + 1;
                Last[i][j] = 3;
            }
            if(A[i] != B[j])
                if(Best[i][j - 1] > Best[i - 1][j]) {
                    Best[i][j] = Best[i][j - 1];
                    Last[i][j] = 2;
                } else {
                    Best[i][j] = Best[i - 1][j];
                    Last[i][j] = 1;
                }
        }
    fout << Best[N][M] << '\n';

    int X = N; int Y = M;
    while(X > 0 && Y > 0) {
        if(Last[X][Y] == 3) {
            Solution.push_back(A[X]);
            --X; --Y;
        }

        if(Last[X][Y] == 2)
            --Y;
        if(Last[X][Y] == 1)
            --X;
    }

    reverse(Solution.begin(), Solution.end());

    for(unsigned i = 0 ;i < Solution.size(); ++i)
        fout << Solution[i] <<" ";

    return 0;
}
