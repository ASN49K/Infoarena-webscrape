/*
 * The longest common subsequence (LCS) problem is to find the longest 
 * subsequence common to all sequences in a set of sequences (often just two)
 */

#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 1024
#define MMAX 1024

int L[NMAX][MMAX];

struct cell {
    short int x;
    short y;
    short val;
};

struct cell c[NMAX][MMAX];

int lcs(vector< short> a, vector<short> b)
{
    int i, j;
    
    if (a[0] == b[0]) {
        L[0][0] = 1;
        c[0][0].x = -1;
        c[0][0].y = -1;
        c[0][0].val = a[0];
    } else {
        c[0][0].x = -1;
        c[0][0].y = -1;
        c[0][0].val = -1;
    }
    
    for (j = 1; j < (int)b.size(); j++) {
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
    
    for (i = 1; i < (int)a.size(); i++) {
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

    for (i = 1; i < (int)a.size(); i++) 
        for (j = 1; j < (int)b.size(); j++) {
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
    return 0;
}

int main(void)
{
    ofstream of("cmlsc.out");
    ifstream ifs("cmlsc.in");
    
    vector <short> a, b;
    short M, N, i, j, x, y;
    short e;
    vector <short> sol;
    
    ifs >> M >> N;
    for (i = 0; i < M; i++) {
        ifs >> e;
        a.push_back(e);
    }

    for (j = 0; j < N; j++) {
        ifs >> e;
        b.push_back(e);
    }
    lcs(a, b);
    
    of << L[a.size()-1][b.size()-1]<<endl;

    i = a.size() - 1;
    j = b.size() - 1;
    do {
        x = c[i][j].x;
        y = c[i][j].y;
       // cout << "This is x:" << x << " y = "<< y<<endl;
        //cout << "This is c[].x "<<c[0][0].x << " "<<c[0][0].y<<endl;
        if (c[i][j].val != -1) 
            sol.push_back(c[i][j].val);
        i = x;
        j = y;
    } while (i != -1 && j != -1);
    
    for (i = sol.size()-1; i >= 0; i--) 
        of << (short int)sol[i]<<" ";
    of << endl;

    return 0;
}
