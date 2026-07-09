//Ilie Dumitru
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

short sol[1030][1030];

int main()
{
    FILE *f=fopen("cmlsc.in", "r"), *g=fopen("cmlsc.out", "w");
    short A[1030], B[1030];
    int i, j, N, M;
    stack<short> st;

    fscanf(f, "%i%i", &N, &M);
    for(i=1;i<=N;++i)
        fscanf(f, "%i", &A[i]);
    for(j=1;j<=M;++j)
        fscanf(f, "%i", &B[j]);
    fclose(f);

    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
        {
            sol[i][j]=max(sol[i-1][j], sol[i][j-1]);
            if(A[i]==B[j] && sol[i-1][j-1]+1>sol[i][j])
                sol[i][j]=sol[i-1][j-1]+1;
        }

    i=N;
    j=M;
    while(sol[i][j])
    {
        if(A[i]==B[j])
        {
            st.push(A[i]);
            --i;
            --j;
        }
        else
        {
            if(sol[i-1][j]==sol[i][j])
                --i;
            else
                --j;
        }
    }

    fprintf(g, "%i\n", sol[N][M]);
    while(!st.empty())
    {
        fprintf(g, "%i ", st.top());
        st.pop();
    }
    fclose(g);
    return 0;
}