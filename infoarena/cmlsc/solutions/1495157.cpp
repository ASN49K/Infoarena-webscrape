#include <fstream>
#include <vector>
using namespace std;

void solve_cmlsc(const vector<unsigned int> &a, const vector<unsigned int> &b, 
                 vector<vector<unsigned char> > &din, 
                 vector< vector<pair<unsigned char, unsigned char> > > &t) {
    for (int i = 1; i < a.size(); ++i) {
        for (int j = 1; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                 din[i][j] = din[i - 1][j - 1] + 1;
                 t[i][j] = make_pair(i - 1, j - 1);
            } else {
                if(din[i][j - 1] > din[i - 1][j]) {
                    din[i][j] = din[i][j - 1];
                    t[i][j] = make_pair(i, j - 1);
                } else {
                    din[i][j] = din[i - 1][j];
                    t[i][j] = make_pair(i - 1, j);
                }
            }
        }
    }
}

ofstream cout("cmlsc.out");

void display(int n, int m, const vector<unsigned int> &a, const vector <unsigned int> &b, 
        const vector<vector<unsigned char> > &din, 
        const vector< vector<pair<unsigned char, unsigned char> > > t) {
    int i = n;
    int j = m;
    cout << (int)din[n][m] << '\n';
    vector<unsigned char> sol;
    while(i && j) {
        if(a[i] == b[j]) {
            sol.push_back(a[i]);
        }
        i = t[i][j].first;
        j = t[i][j].second;
    }

    for (int k = sol.size() - 1; k >= 0; --k) {
        cout << (int) sol[k] << " ";
    }

    cout << '\n';
}

int main() { 
    ifstream cin("cmlsc.in");
    int n, m;
    cin >> n >> m;
    vector<unsigned int> a(n + 1), b(m + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int j = 1; j <= m ; ++j) {
        cin >> b[j];
    }
    vector<vector<unsigned char> > din(n + 1);
    vector<vector<pair<unsigned char, unsigned char> > > t(n + 1);
    for (int i = 0; i <= n; ++i) {
        vector<unsigned char> x(m + 1);
        din[i] = x;
        for (int j = 0; j <= m; ++j) {
            t[i].push_back(make_pair(0, 0));
        }
    }

    solve_cmlsc(a, b, din, t); 
    display(n, m, a, b, din, t);

    return 0;
}
