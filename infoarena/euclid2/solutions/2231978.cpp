#include <fstream>
const std::string programName = "euclid2";
std::ifstream f(programName + ".in");
std::ofstream g(programName + ".out");
int main() {
    int T;
    f >> T;
    while (T--) {
        int a, b, r;
        f >> a >> b;
        while(b) {
            r = a % b;
            a = b;
            b = r;
        }
        g << a << "\n";
    }
    return 0x0;
}
