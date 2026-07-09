#include <stdio.h>
#include <algorithm>

FILE *in = fopen("cmlsc.in","r");
FILE *out = fopen("cmlsc.out","w");

int N, M;

int X[1029], Y[1029];
int D[1029][1029];
int Sub[1029];

void _read()
{
    fscanf(in, "%d %d", &N, &M);

    for(int i=1; i<=N; ++i)
    {
        fscanf(in, "%d", &X[i]);
    }

    for(int i=1; i<=M; ++i)
    {
        fscanf(in, "%d", &Y[i]);
    }
}

/*
    1 - left
    2 - up/left
    3 - up
*/
int main()
{
    _read();

    for(int j=0; j<=M; ++j)
        D[0][j] = 0;

    for(int i=1; i<=N; ++i)
    {
        D[i][0] = 0;

        for(int j=1; j<=M; ++j)
        {
            if(X[i]==Y[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
            {
                D[i][j] = std::max(D[i-1][j], D[i][j-1]);
            }
        }
    }


    int i = N, j = M;
    int len = 0;

    while(i > 0 && j > 0)
    {
        if(X[i]==Y[j])
        {
            Sub[len] = X[i]; ++len; --i; --j;
        }
        else if(D[i][j-1] < D[i-1][j])
            --i;
        else
            --j;

    }

    fprintf(out, "%d\n", len);
    for(int i=len-1; i>=0; --i)
    {
        fprintf(out, "%d ", Sub[i]);
    }

    return 0;
}
