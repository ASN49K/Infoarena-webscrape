#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int ult[1025][1025] = {-1}; 
int l[1025][1025] = {0};

int main() {
    int n, m;
    int v1[1025], v2[1025];
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> v1[i];
    for(int j = 1; j <= m; j++)
        fin >> v2[j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(v1[i] != v2[j]) {
                if(l[i][j - 1] > l[i - 1][j]) {
                    ult[i][j] = ult[i][j - 1];
                    l[i][j] = l[i][j - 1];
                } else {
                    ult[i][j] = ult[i - 1][j];
                    l[i][j] = l[i - 1][j];
                }
            } else {
                ult[i][j] = j;
                l[i][j] = l[i - 1][j - 1] + 1;
            }
        }
    stack <int> st;
    fout << l[n][m] << endl;
    int p = ult[n][m];
    for(int i = 0; i < l[n][m]; i++) {
        st.push(v2[p]);
        p = ult[p - 1][p - 1];
    }
    while(!st.empty()) {
        fout << st.top() << " ";
        st.pop();
    }
    fin.close();
    fout.close();
    return 0;
}