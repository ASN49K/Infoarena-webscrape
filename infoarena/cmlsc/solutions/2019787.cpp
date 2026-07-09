#include <bits/stdc++.h>
using namespace std;

class InputReader {
    public:
        InputReader() {}
        InputReader(const char *file_name) {
            input_file = fopen(file_name, "r");
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, input_file);
            }
        }
};

char a[1100], b[1100];
short int dp[1100][1100];
int n, m;
char r[1100];

int main()
{
    InputReader in("cmlsc.in");
    freopen("cmlsc.out", "w", stdout);
    in >> n >> m;
    register int x;
    for (int i(1); i <= n; i++) {
        in >> x;
        a[i] = x;
    }
    for (int i(1); i <= m; i++) {
        in >> x;
        b[i] = x;
    }

    for (register int i(1); i <= n; i++) {
        for (register int j(1); j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int ans = dp[n][m];
    int cnt(ans);
    cout << ans << "\n";
    for (register int i(n), j(m); i && j; ) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
            continue;
        }
        if (dp[i][j] == dp[i][j - 1]) {
            j--;
            continue;
        }

        r[cnt--] = a[i];
        i--, j--;
    }

    for (int i(1); i <= ans; i++)
        cout << ((int)r[i]) << ' ';

    return 0;
}

