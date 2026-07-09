#include <fstream>
const std::string programName = "cmlsc";
std::ifstream f(programName + ".in");
std::ofstream g(programName + ".out");
const int MAX = 260;
int N, M, A[MAX], B[MAX], sir[MAX], counter, sol[MAX];
bool valid(int);
void back(int, int);
int main() {
    f >> N >> M;
    for (int i = 1; i <= N; ++i)
        f >> A[i];
    for (int i = 1; i <= M; ++i)
        f >> B[i];
    back(1, 0);
    g << counter << "\n";
    for (int i = 1; i < counter; ++i)
        g << sol[i] << ' ';
    g << sol[counter] << "\n";
    return 0x0;
}
bool valid(int k) { // daca sir[1..k] este subsir pentru B[1..N]
    int j = 1;
    for (int i = 1; i <= k; ++i)
        for (; j <= M and B[j] != sir[i]; ++j);
    return j <= M;
}
void back(int k, int length) {
    if (k == N + 1) {
        if (valid(length)) //daca sir e subsir si pentru B
            if (length > counter) {
                counter = length;
                for (int i = 1; i <= counter; ++i)
                    sol[i] = sir[i];
            }
            return;
    }
    back(k + 1, length);
    sir[length + 1] = A[k];
    back(k + 1, length + 1);
}
