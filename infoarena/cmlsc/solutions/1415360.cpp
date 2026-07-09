#include <cstdio>
#define N 1030

using namespace std;

int n, m, a[N], b[N], mat[N][N];

void read() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
}

int maxim(int a, int b) {
    if(a > b)
        return a;
    return b;
}

void generate_matrix() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            mat[i][j] = maxim(mat[i-1][j], mat[i][j-1]);
            if(a[i] == b[j])
                mat[i][j] = mat[i-1][j-1]+1;
        }
}

void drum(int i, int j) {
    if(mat[i][j] == 0)
        return;
    if(a[i] == b[j]) {
        drum(i-1, j-1);
        printf("%d ", a[i]);
        //printf("%d %d\n", i, j);
        return;
    }
    if(mat[i][j-1] < mat[i-1][j]) {
        drum(i-1, j);
        return;
    }
    drum(i, j-1);
}

void afisare() {
    printf("\n");
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++)
            printf("%d", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    read();
    generate_matrix();
    printf("%d\n", mat[n][m]);
    drum(n, m);
    //afisare();
    return 0;
}
