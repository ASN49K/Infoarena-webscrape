#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v[1030], x;
unordered_map<int, int> fr;
vector<int> sol;

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fin >> v[i];
        fr[v[i]]++;
    }
    for(int i = 1; i <= m; i++) {
        fin >> x;
        fr[x]++;
    }
    fin.close();
    for(int i = 1; i <= n; i++) {
        if(fr[v[i]] >= 2) {
            sol.push_back(v[i]);
            fr[v[i]] -= 2;
        }
    }
    fout << sol.size() << "\n";
    for(int it : sol) {
        fout << it << " ";
    }
    fout.close();
    return 0;
}
