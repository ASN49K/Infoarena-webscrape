using namespace std;
#include<bits/stdc++.h>

ifstream fin("nim.in");
ofstream fout("nim.out");

int nrteste;
int n;

int main() {
    
    fin >> nrteste;
    
    for (int i = 1; i<=nrteste; i++) {
        fin >> n;
        int sum = 0;
        int x;
        for (int i = 1; i<=n; i++) {
            fin >> x;
            sum ^= x;
        }
        
        if (sum) {
            fout << "DA\n";
        } else {
            fout << "NU\n";
        }
    }
    
    return 0;
}
