#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");

int x1[1025], x2[1025];
unsigned short int din[1025][1025];
int l1, l2;
vector<int> sol;

void read() {
    fin >> l1 >> l2;
    for(int i = 1; i <= l1; i++)
        fin >> x1[i];
    for(int i = 1; i <= l2; i++)
        fin >> x2[i];
}

void build() {
    for(int i = 1; i <= l1; i++) {
        for(int j = 1; j <= l2; j++) {
            if(x1[i] == x2[j])
                din[i][j] = din[i - 1][j - 1] + 1;
            else
                din[i][j] = max(din[i - 1][j], din[i][j - 1]);
        }
    }
}

void print() {
    for(int i = sol.size() - 1; i >= 0; i--)
        fout << sol[i] << " ";
}

void solve() {
    fout << din[l1][l2] << "\n";
    int i = l1, j = l2;
    while(i && j) {
        if(din[i][j] > din[i - 1][j] && din[i][j] > din[i][j - 1])
            sol.push_back(x1[i]), i--, j--;
        else if(din[i - 1][j] > din[i][j - 1])
            i--;
        else
            j--;
    }
    print();
}

void fclose() {
    fin.close(), fout.close();
}

int main() {
    read();
    build();
    solve();
    fclose();
    return 0;
}