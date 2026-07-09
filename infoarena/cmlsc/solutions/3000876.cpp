#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");


int main()
{
    int M, N;
    fin >> M >> N;
    vector<int> A(M);
    vector<int> B(N);

    for(int i = 0; i < M; i++)
    {
        fin >> A[i];
    }

    for(int i = 0; i < N; i++)
    {
        fin >> B[i];
    }
    vector<int> v;
    int p = 0, pos = 0;
    for(int i = 0; i < M; i++)
    {
        if(B[p] == A[i])
        {
            v.push_back(B[p]);
            p++;
            pos = i;
        }
        if(p < N - 1 && i == M - 1)
        {
            i = pos;
            p++;
        }
        if(p == N)
        {
            p--;
            break;
        }
    }


    fout << p << endl;
    for(int i = 0; i < p; i++)
    {
        fout << v[i] << " ";
    }


    return 0;
}
