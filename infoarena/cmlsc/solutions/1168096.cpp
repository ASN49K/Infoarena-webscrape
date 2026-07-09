#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

template<class S, class T>
class Solution {
public:
    Solution(const char*);
    void compute();
    void writeOutput(const char*);

private:
    void construct(S, S);
    void readArray(S, vector<T>&);
    void readInput();

    vector<T> a, b, s;
    vector<vector<T> > c;
    ifstream in;
};

template<class S, class T>
Solution<S, T>::Solution(const char* fileName) {
    in.open(fileName, ifstream::in);
    readInput();
    in.close();
}

template<class S, class T>
void Solution<S, T>::readArray(S n, vector<T>& v) {
    long num;
    v.reserve(n);
    for (S i = 0; i < n; ++i) {
        in >> num;
        v.push_back(num);
    }
}

template<class S, class T>
void Solution<S, T>::readInput() {
    S m, n;
    in >> m;
    in >> n;
    readArray(m, a);
    readArray(n, b);
}

template<class S, class T>
void Solution<S, T>::writeOutput(const char* fileName) {
    ofstream out(fileName, ofstream::out);
    out << s.size() << endl;;
    for (S i = 0; i < s.size(); ++i) {
        out << (long) s[i] << " ";
    }
    out << endl;
    out.close();
}

template<class S, class T>
void Solution<S, T>::compute() {
    S m = a.size(), n = b.size();
    c.resize(m + 1);
    for (S i = 0; i <= m; ++i) {
        c[i].resize(n + 1, 0);
    }
    for (S i = 1; i <= m; ++i) {
        for (S j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            } else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    construct(m, n);
}

template<class S, class T>
void Solution<S, T>::construct(S i, S j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (a[i - 1] == b[j - 1]) {
        construct(i - 1, j - 1);
        s.push_back(a[i - 1]);
    } else if (c[i - 1][j] > c[i][j - 1]) {
        construct(i - 1, j);
    } else {
        construct(i, j - 1);
    }
}

int main(int argc, char **argv) {
    Solution<uint16_t, uint8_t> s("cmlsc.in");
    s.compute();
    s.writeOutput("cmlsc.out");
    return 0;
}
