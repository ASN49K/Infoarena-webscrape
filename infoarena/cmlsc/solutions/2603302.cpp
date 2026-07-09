#include <cstdio>
#include <stack>

short A[1030], B[1030], M[1030][1030], n, m ,i, j, temp;
std::stack<int> st;

int max(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int main() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; ++i)
        scanf("%d", &A[i]);
    for(i = 1; i <= m; ++i)
        scanf("%d", &B[i]);

    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j) {
            M[i][j] = max(M[i-1][j], M[i][j-1]);
            if(A[i] == B[j])
                ++M[i][j];
        }

    printf("%d\n", M[n][m]);
    temp = M[n][m];
    i = n;
    j = m;
    while(i > 0 && j > 0) {
        if(A[i] == B[j])
            st.push(A[i]);
        if(M[i-1][j] > M[i][j-1])
            --i;
        else
            --j;
    }
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
}
