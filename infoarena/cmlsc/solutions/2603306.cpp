#include <cstdio>
#include <stack>

int A[1030], B[1030], M[1030][1030], n, m, i, j;
std::stack<int> st;

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for(i = 1; i <= m; ++i)
        scanf("%d", &B[i]);

    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            if(A[i] == B[j])
                M[i][j] = 1 + M[i-1][j-1];
            else
                M[i][j] = std::max(M[i-1][j], M[i][j-1]);

    printf("%d\n", M[n][m]);

    i = n, j = m;
    while(i && j) {
        if(A[i] == B[j]) {
            st.push(A[i]);
            --i;
            --j;
        }
        else if(M[i-1][j] > M[i][j-1])
            --i;
        else
            --j;
    }
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
}
