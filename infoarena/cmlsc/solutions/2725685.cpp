#include<fstream>
#include<stack>

using namespace std;

const int MAX_N = 1025;
int N, M;
int a[MAX_N], b[MAX_N], dp[MAX_N][MAX_N];

int build_lcs() {
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[N][M];
}

void rebuild_sequence(ofstream& fout) {
    stack<int> seq;
    int i = N, j = M;
    while(i != 0 && j != 0) {
        if (a[i] == b[j]) {
            seq.push(a[i]);
            i--, j--;
        } else
            dp[i-1][j] > dp[i][j-1] ? i--:j--;
    }
    while(!seq.empty()) {
        fout << seq.top() << ' ';
        seq.pop();
    }
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> N >> M;
    for (int i = 1; i <= N; i++) {
        fin >> a[i];
    }
    for (int i = 1; i <= M; i++) {
        fin >> b[i];
    }

    fin.close();

    fout << build_lcs() << "\n";
    rebuild_sequence(fout);
    fout.close();
}
