#include<stdio.h>
#include<fstream>
#include<iostream>
#include<vector>
using namespace std;

#define max(a,b) ((a > b) ? a : b) 
#define MAX 1024

int n, m;
short a[MAX], b[MAX];
int best[MAX + 1][MAX + 1];
int subseq[MAX]; 
int max_len;

void solve()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m ; ++j)
            if (a[i] == b[j])
                best[i + 1][j + 1] = 1 + best[i][j];
            else
                best[i + 1][j + 1] = max(best[i][j+1], best[i+1][j]); 
    
    max_len = best[n][m];
    int i = n;
    int j = m;
    int k = max_len;
    while (best[i][j] > 0)
    {
        if (a[i - 1] == b[j - 1]){
            subseq[--k] = a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (best[i][j - 1] > best[i - 1][j])
                --j;
            else
                --i;
        }
    }  
}



int main()
{
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for (int i = 0; i < n; ++i)
        fin >> a[i];
    for (int i = 0 ; i < m; ++i)
        fin >> b[i];
    fin.close(); 
    
    solve();
    
    ofstream fout("cmlsc.out");
    fout << max_len << "\n";
    for (int i = 0; i < max_len; i++)
        fout << subseq[i] << " ";
    fout.close();

    return 0;
}

