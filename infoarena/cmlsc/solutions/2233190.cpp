#include <fstream>
const std::string programName = "cmlsc";
std::ifstream f(programName + ".in");
std::ofstream g(programName + ".out");
const int MAX = 1e3;
int main() {
    int N, M, A[MAX + 25];
    f >> N >> M;
    for (int i = 1; i <= N; ++i)
        f >> A[i];
    int B[MAX + 25];
    for (int i = 1; i <= M; ++i)
        f >> B[i];
    int counter = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
                ++counter;
    g << counter << "\n";
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
                g << A[i] << ' ';
    return 0x0;
}
