#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int T , n , x;

int main() {
    f >> T;
    while(T--) {
        f >> n >> x;
        int sum = x;
        for(int i = 2 ; i <= n ; ++i) {
            f >> x;
            sum = sum ^ x;
        }

        if(sum != 0) {
            g << "DA\n";
        }

        else {
            g << "NU\n";
        }
    }
    return 0;
}
