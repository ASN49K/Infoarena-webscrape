#include <bits/stdc++.h>

using namespace std;

int C[1030][1030], MAXIM;
int A[1030], B[1030], M, N;
int solutie[1030];
int contor;

int CMLSC(int A[], int B[], int M, int N, int C[1030][1030])
{
    for(int i = 1;i <= M; ++i)
        for(int j = 1;j <= N; ++j)
        {
            if(i == 0 || j == 0)
                C[i][j] = 0;
            else
                if(A[i] == B[j])
                    C[i][j] = C[i - 1][j - 1] + 1;
                else
                    C[i][j] = max(C[i - 1][j], C[i][j - 1]);
        }
    MAXIM = C[M][N];
    return MAXIM;
}

void SubsirMaxim(int A[], int B[], int M, int N, int C[1030][1030], int solutie[])
{
    int i = M;
    int j = N;
    while(C[i][j]){
        if(C[i][j] > max(C[i][j - 1],C[i - 1][j]))
        {
            solutie[++contor] = A[i];
             i -= 1;
             j -= 1;
        }
        else
            if(C[i][j] == C[i - 1][j])
                i -= 1;
            else
                if(C[i][j] == C[i][j - 1])
                    j -= 1;
    }
}

void afisare()
{
    for(int i = contor; i > 0; --i)
        cout << solutie[i] << " ";
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    cin >> M >> N;

    for(int i = 1;i <= M; ++i)
        cin >> A[i];
    for(int i = 1;i <= N; ++i)
        cin >> B[i];

    cout << CMLSC(A,B,M,N,C);
    cout << '\n';

    SubsirMaxim(A,B,M,N,C,solutie);
    afisare();
    return 0;
}
