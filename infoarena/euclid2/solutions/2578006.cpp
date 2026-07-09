#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n;
vector<int> v;

int euclid(int a, int b) {
    if (!b)
        return a;
    return euclid(b, a % b);
}

int main(int argc, const char * argv[]) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        int ans = euclid(a, b);
        v.push_back(ans);
    }
    for (int i = 0; i < v.size(); i++)
        fout << v[i] << "\n";
}
