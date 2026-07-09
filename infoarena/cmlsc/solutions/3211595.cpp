#include <bits/stdc++.h>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

stack<int> Galeata;
int M, N, A[1025], B[1025], Matrix[1025][1025], LMax=0, iMax, jMax;
int Max[1025], Min[1025];
int main()
{
    int Lin, Col;
    fin >> M >> N;
    for(int i=1; i<=M; i++) fin >> A[i];
    for(int i=1; i<=N; i++) fin >> B[i];
    if(M > N)
    {
        // #define A Max ??
        Lin = M; Col = N;
        copy(begin(A), end(A), begin(Max));
        copy(begin(B), end(B), begin(Min));
        // Max = A; Min = B;
    }
    else
    {
        Lin = N; Col = M;
        copy(begin(B), end(B), begin(Max));
        copy(begin(A), end(A), begin(Min));
        // Max = B; Min = A;
    }
    // Lin = max(M, N);
    // Col = min(M, N);
    for(int i=1; i<=Lin; i++)
    {
        for(int j=1; j<=Col; j++)
        {
            if(Min[j] == Max[i]) 
            {
                Matrix[i][j]=Matrix[i-1][j-1]+1;
                if(Matrix[i][j] > LMax)
                {
                    LMax = Matrix[i][j];
                    iMax = i; jMax = j;
                }
            }
            else Matrix[i][j] = max(Matrix[i-1][j], Matrix[i][j-1]);
        }
    }
    
    fout << Matrix[iMax][jMax] << "\n";

    int i=iMax, j=jMax;
    while(i>0 && j>0)
    {
        if(A[i] == B[j])
        {
            Galeata.push(A[i]);
            i--; j--;
        }
        else
        {
            if(Matrix[i-1][j] > Matrix[i][j-1]) i--;
            else j--;
        }
    }
    
    while(!Galeata.empty())
    {
        fout << Galeata.top() << " ";
        Galeata.pop();
    }
    return 0;
}