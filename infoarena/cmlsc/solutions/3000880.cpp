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
    int p = 0, pos = 0, cnt = 0;
    if(M > N)
    {
        for(int i = 0; i < M; i++)
    {
        if(B[p] == A[i])
        {
            v.push_back(B[p]);
            p++;
            cnt++;
            pos = i;
        }
        if(p < N - 1 && i == M - 1)
        {
            i = pos;
            p++;
        }
        if(p == N)
        {
            break;
        }
    }
    }
    else
    {
        for(int i = 0; i < N; i++)
    {
        if(B[i] == A[p])
        {
            v.push_back(A[p]);
            p++;
            cnt++;
            pos = i;
        }
        if(p < M - 1 && i == N - 1)
        {
            i = pos;
            p++;
        }
        if(p == M)
        {
            break;
        }
    }
    }



    fout << cnt << endl;
    for(int i = 0; i < cnt; i++)
    {
        fout << v[i] << " ";
    }


    return 0;
}
