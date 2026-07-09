#include <fstream>

const int MAX_N = 1005;

std::ifstream fin;
std::ofstream fout;

int M, N;
int a[MAX_N], b[MAX_N];
int mat[MAX_N][MAX_N];
int sir[MAX_N];

inline int max(int a, int b) {
    return (a > b ? a : b);
}

int main(int argc, char const *argv[])
{
    fin.open("cmlsc.in");
    fin >> M >> N;
    for (int i = 1; i <= M; ++i) {
        fin >> a[i];
    }
    for (int i = 1; i <= N; ++i) {
        fin >> b[i];
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (a[i] == b[j]) {
                mat[i][j] = mat[i-1][j-1] + 1;
            } else {
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
            }
        }
    }

    int lmax = 0;
    for (int i = M, j = N; i; ) {
        if (a[i] == b[j]) {
            sir[++lmax] = a[i];
            --i;
            --j;
        } else if (mat[i-1][j] < mat[i][j-1]) {
            --j;
        } else {
            --i;
        }
    }

    fout.open("cmlsc.out");
    fout << lmax << '\n';
    for (int i = lmax; i > 0; --i) {
        fout << sir[i] << ' ';
    }
    fout.close();
    return 0;
}