#include<fstream>

int main() {
    std::ifstream fin("euclid2.in");
    std::ofstream fout("euclid2.out");

    int a, b, t;

    fin >> t; // skip over the first line
    
    for (;fin >> a >> b;) {
        while (b) {
            t = b;
            b = a % b;
            a = t;
        }

        fout << a << '\n';
    }
    
    return 0;
}