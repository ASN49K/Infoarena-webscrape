#include <fstream>
#include <vector>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

vector<pair<int, int>> read() {
    vector<pair<int, int>> nums;
    int n, a, b;
    in >> n;
    for(; n; --n) {
        in >> a >> b;
        nums.push_back(pair<int, int>(a, b));
    }

    return nums;
}

vector<int> solve(vector<pair<int, int>> nums) {
    vector<int> res;
    for(auto pair : nums) {
        int a = pair.first, b = pair.second;
        int r = a % b;
        a = b;
        b = r;
        while(b != 0) {
            r = a % b;
            a = b;
            b = r;
        }
        res.push_back(a);
    }

    return res;
}

void print(vector<int> res) {
    for(auto r : res) {
        out << r << '\n';
    }
}

int main() {
    auto nums = read();
    auto res = solve(nums);
    print(res);

    return 0;
}