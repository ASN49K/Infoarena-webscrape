#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

inline int maxx(const int a, const int b){
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n;
    int m;
    cin >> n;
    cin >> m;
    
    n++, m++;
    vector<int> a(n);
    for (int i = 1; i < n; i++)
        cin >> a[i];
    
    vector<int> b(m);
    for (int i = 1; i < m; i++)
        cin >> b[i];
    
    vector<vector<int> > d(n, vector<int>(m, 0));
    
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
    else
        d[i][j] = maxx(d[i - 1][j], d[i][j - 1]);
    
    int i = n - 1;
    int j = m - 1;
    int index = 0;
    vector<int> sir(n + m);
    while (i){
        if (a[i] == b[j]){
            sir[index++] = a[i];
            i--;
            j--;
        }
        else if (d[i - 1][j] < d[i][j - 1])
            j--;
        else
            i--;
    }
    
    cout << index << '\n';
    while (index)
        cout << sir[--index] << ' ';
    
    cin.close();
    cout.close();
    return 0;
}
