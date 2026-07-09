/*
    Backtracking solution
    Runtime: O(2^n) (exponential)
    Memory: O(min(n, m))
*/

#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

bool is_subseq(int len, int n, int s[], int b[]) {
    /* Checks if s[1...len] is a subsequence of b[1...n].*/
    if(len > n) {
        return 0;
    }
    int i=0, j=0;
    while(i < len && j < n) {
        while(s[i]!=b[j] && j < n) {
            j++;
        }
        if(j == n) {
            return 0;
        }
        i++;
    }
    return 1;
}

void bkt(int lev, int len, int m, int n, int& sol_n, int a[], int b[], int s[], int sol[]) {
    if(lev == m) {
        if(is_subseq(len, n, s, b)) {
            if(len > sol_n) {
                sol_n = len;
                for(int i=0; i<len; i++) {
                    sol[i] = s[i];
                }
            }
        }
        return ;
    }

    bkt(lev+1, len, m, n, sol_n, a, b, s, sol);
    s[len] = a[lev];
    bkt(lev+1, len+1, m, n, sol_n, a, b, s, sol);
}

int main()
{
    int m, n, sol_n=0, a[1030], b[1030], sol[1030] = {0}, s[1030] = {0};

    fin >> m >> n;
    for(int i=0; i<m; i++) {
        fin >> a[i];
    }
    for(int i=0; i<n; i++) {
        fin >> b[i];
    }

    bkt(0, 0, m, n, sol_n, a, b, s, sol);

    fout << sol_n << '\n';
    for(int i=0; i<sol_n; i++) {
        fout << sol[i] << ' ';
    }
    return 0;
}
