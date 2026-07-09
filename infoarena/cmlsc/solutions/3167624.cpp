//https://www.youtube.com/watch?v=Ua0GhsJSlWM&t=2s -> LCS explained
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define maxim(a, b) ((a>b)? a : b)
#define NMax 1024

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

vector<int>A, B(NMax);
vector<vector<int>>C(NMax+1, vector<int>(NMax+1, 0));

int m, n;

void readVectors()
{
    fin >> m >> n;
    A.resize(m);
    B.resize(n);
    for (int i=0; i<m; i++)
        fin >> A[i];
    for (int i=0; i<n; i++)
        fin >> B[i];
    C.resize(m+1, vector<int>(n+1, 0));
}

int main()
{ 
    int max;
    readVectors();

    for (int i=m-1; i>=0; i--)
        for (int j=n-1; j>=0; j--)
            if (A[i] == B[j])
                C[i][j] = 1 + C[i+1][j+1];
            else
                C[i][j] = maxim(C[i][j+1], C[i+1][j]);
    
    int i=0, j=0;
    vector<int>subsequence;
    while (i < m && j < n)
    {
        if (A[i] == B[j])
        {
            subsequence.push_back(A[i]);
            i++;
            j++;
        }
        else if (C[i][j+1] >= C[i+1][j])
            j++;
        else
            i++;
    }

    fout << subsequence.size() << endl;
    for (auto i : subsequence)
        fout << i << " ";
    
    fin.close();
    fout.close();
    return 0;
}