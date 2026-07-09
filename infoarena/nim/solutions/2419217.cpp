#include <fstream>
using namespace std;

const string FILE_NAME = "nim";

ifstream in { FILE_NAME + ".in" };
ofstream out { FILE_NAME + ".out" };

int main() {
    ios_base::sync_with_stdio(false);
    in.tie(0);
    out.tie(0);
    
    int t;
    in >> t;
    
    while (t--) {
        int n;
        in >> n;
        
        int s { 0 };
        while (n--) {
            int x;
            in >> x;
            s ^= x;
        }
        
        out << (s ? "DA\n" : "NU\n");
    }
}
