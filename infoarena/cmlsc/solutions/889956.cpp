#include <iostream>
#include <fstream>

using namespace std;

#define Max 1024
#define maxim(a,b) ((a>b)?a:b)

int M, N, A[Max], B[Max], c[Max][Max], sir[Max], bst;

int main()
{
    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");
    int i, j;

    in>>M>>N;
    for(i = 1; i <= M; i++)
        in>>A[i];
    for(j = 1; j <= N; j++)
        in>>B[j];

    for(i = 1; i <= M; i++)
        for(j = 1; j <= N; j++)
        {
            if(A[i] == B[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = maxim(c[i-1][j], c[i][j-1]);
        }

    for(i = M, j = N; i; )
    {
        if(A[i] == B[j])
        {
            sir[++bst] = A[i];
            --i;
            --j;
        }

        else
            if(c[i-1][j] < c[i][j-1])
                --j;
            else
                --i;
    }

    out<<bst<<"\n";
    for(i = bst; i >= 1; i--)
        out<<sir[i]<<" ";


    return 0;
}
