#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> cmlsc(const vector<int> &A, const vector<int> &B) {
    int N = A.size(), M = B.size(), i = 0, j = 0, up = 0, left = 0;
    vector< vector<int> > DP(N, vector<int>(M, 0));
    vector<int> sol;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (A[i] == B[j]) {
                DP[i][j] = i == 0 ? 1 : (j == 0 ? 1 : 1 + DP[i - 1][j - 1]);
            } else {
                up = i > 0 ? DP[i - 1][j] : 0;
                left = j > 0 ? DP[i][j-1] : 0;
                DP[i][j] = max(left, up);
            }
        }
    }

    for (i = N - 1, j = M - 1; i >= 0 && j >= 0;) {
        if (A[i] == B[j]) {
            sol.push_back(A[i]);
            i--;
            j--;
        } else {
            if (i == 0) j--;
            else if (j == 0) i--;
            else if (DP[i-1][j] > DP[i][j - 1]) i--;
            else j--;
        }
    }

    reverse(sol.begin(), sol.end());
    return sol;
}


int main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> A(N, 0), B(M, 0);
    for (int i = 0; i < N; i++) cin>>A[i];
    for (int i = 0; i < M; i++) cin>>B[i]; 

    vector<int> sol = cmlsc(A, B);

    cout << sol.size() << endl;
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << ' ';
    }

    return 0;
}
