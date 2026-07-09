/*
 * The longest common subsequence (LCS) problem is to find the longest 
 * subsequence common to all sequences in a set of sequences (often just two)
 */

#include <vector>
#include <iostream>

using namespace std;

#define NMAX 1024
#define MMAX 1024

int L[NMAX][MMAX];
int R[NMAX][NMAX];

struct cell {
    int x;
    int y;
    int val;
};

struct cell c[NMAX][MMAX];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(vector<int> a, vector<int> b)
{
    int len = 0;
    int i, j;
    
    if (a[0] == b[0]) {
        L[0][0] = 1;
        R[len][len] = a[0];
        c[0][0].x = -1;
        c[0][0].y = -1;
        c[0][0].val = a[0];
    }
    
    for (j = 1; j < b.size(); j++) {
        if (a[0] == b[j]) {
            L[0][j] = 1;
            c[0][j].x = c[0][j].y = -1;
            c[0][j].val = a[0];
        } else {
            L[0][j] = L[0][j-1];
            c[0][j].x = 0;
            c[0][j].y = j-1;
            c[0][j].val = -1;
        }
    }
    
    for (i = 1; i < a.size(); i++) {
        if (a[i] == b[0]) {
            L[i][0] = 1;
            c[i][0].x = c[i][0].y = -1;
            c[i][0].val = b[0];
        } else {
            L[i][0] = L[i-1][0];
            c[i][0].x = i-1;
            c[i][0].y = 0;
            c[i][0].val = -1;
        }
    }

    for (i = 1; i < a.size(); i++) 
        for (j = 1; j < b.size(); j++) {
            if (a[i] == b[j]) {
                L[i][j] = 1 + L[i-1][j-1];
                c[i][j].x = i-1;
                c[i][j].y = j-1;
                c[i][j].val = a[i];
            } else {
                    if ( (L[i-1][j] >= L[i][j-1]) && (L[i-1][j] >= L[i-1][j-1]) ) {
                        c[i][j].x = i-1;
                        c[i][j].y = j;
                        c[i][j].val = -1;
                        L[i][j] = L[i-1][j];
                    } else {
                        if (L[i][j-1] >= L[i-1][j-1]) {
                             c[i][j].x = i;
                             c[i][j].y = j-1;
                             c[i][j].val = -1;
                             L[i][j] = L[i][j-1];
                        } else {
                                c[i][j].x = i - 1;
                                c[i][j].y = j - 1;
                                c[i][j].val = -1;
                                L[i][j] = L[i-1][j-1];
                        }
                }
            }
        }   
}

int main(void)
{
    vector <int> a, b;
    int M, N, i, j, e, x, y;
    vector <int> sol;
    
    cin >> M >> N;

    for (i = 0; i < M; i++) {
        cin >> e;
        a.push_back(e);
    }

    for (j = 0; j < N; j++) {
        cin >> e;
        b.push_back(e);
    }

    lcs(a, b);

    cout << L[a.size()-1][b.size()-1]<<endl;

    i = a.size() - 1;
    j = b.size() - 1;
    do {
        x = c[i][j].x;
        y = c[i][j].y;
        if (c[i][j].val != -1) 
            sol.push_back(c[i][j].val);
        i = x;
        j = y;
    } while (i != -1 && j != -1);
    
    for (i = sol.size()-1; i >= 0; i--) 
        cout << sol[i]<<" ";
    cout << endl;

    return 0;
}
