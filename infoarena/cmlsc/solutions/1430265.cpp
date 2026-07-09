#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1030], b[1030], d[1030][1030];

int main() 
{   
    int M,  N;
    fin >> M >> N;
    for (int i = 0; i < M; i++) {
        int x;
        fin >> x;
        a[i] = x;
    }

    for (int i = 0; i < N; i++) {
        int x;
        fin >> x;
        b[i] = x;
    }

    int m = 0;
    for (int i = 0; i < M; i++) {
        if (a[i] == b[0]) {
            m = 1;
        }
        d[i][0] = m;
    }

    m = 0;
    for (int i = 0; i < N; i++) {
        if (b[i] == a[0]) {
            m = 1;
        }
        d[0][i] = m;
    }

    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            d[i][j] = max(d[i-1][j-1] + ((a[i] == b[j]) ? 1 : 0), 
                      max(d[i - 1][j], d[i][j - 1]));
        }
    }

    fout << d[M-1][N-1]<< endl;

    vector<int> sol;
    int i = M - 1, j = N - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            sol.push_back(a[i]);
            i--;
            j--;
        }
        else if (d[i - 1][j] > d[i][j - 1]) {
            i--;
        }
        else j--;
    }
    for (int i = sol.size() - 1; i >= 0; i--) {
        fout << sol[i] << " ";
    }
    fout.close();
    fin.close();

}
