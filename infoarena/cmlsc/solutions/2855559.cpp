#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int nmax = 1030;
int lungime_max[nmax][nmax];

int main() {
    int len1, len2;
    fin >> len1 >> len2;

    int s1[nmax], s2[nmax];

    for(int i = 1; i <= len1; ++i)
        fin >> s1[i];

    for(int j = 1; j <= len2; ++j)
        fin >> s2[j];

    for(int i = 1; i <= len1; ++i)
        for(int j = 1; j <= len2; ++j)
            if(s1[i] == s2[j])
                lungime_max[i][j] = 1 + lungime_max[i - 1][j - 1];
            else
                lungime_max[i][j] = max(lungime_max[i - 1][j], lungime_max[i][j - 1]);

    fout << lungime_max[len1][len2] << '\n';

    stack<int> st;
    int i, j;
    for (i = len1, j = len2; i && j;)
        if (s1[i] == s2[j]) {
            st.push(s1[i]);
             --i, --j;
        }
        else if (lungime_max[i-1][j] < lungime_max[i][j-1])
            --j;
        else
            --i;

    while(st.size()) {
        fout << st.top() << ' ';
        st.pop();
    }


    return 0;
}
