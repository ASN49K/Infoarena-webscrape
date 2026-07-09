#include <cstdio>
#include <stack>

#define Max_Size 1027

using namespace std;

const char iname[] = "cmlsc.in";
const char oname[] = "cmlsc.out";

int N, M, A[Max_Size], B[Max_Size], PD[Max_Size][Max_Size];

stack < int > Sol;

inline void Read_Data()
{
    FILE *in = fopen(iname, "r");

    fscanf(in, "%d%d", &N, &M);

    for(int i = 1; i <= N; ++i) fscanf(in, "%d", &A[i]);
    for(int i = 1; i <= M; ++i) fscanf(in, "%d", &B[i]);
}

inline void Write_Data()
{
    FILE *out = fopen(oname, "w");

    fprintf(out, "%d\n", PD[N][M]);

    for(int i = N, j = M, p = 1; p <= PD[N][M];)    {
        if(A[i] == B[j])    {
            Sol.push(A[i]);
            --i, --j, ++p;

            continue;
        }

        if(PD[i - 1][j] == PD[i][j])    --i;
        else                            --j;
    }

    while(!Sol.empty()) {
        fprintf(out, "%d ", Sol.top());
        Sol.pop();
    }
}

int main()
{
    Read_Data();

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            if(A[i] == B[j])    PD[i][j] = PD[i - 1][j - 1] + 1;
            else                PD[i][j] = max(PD[i - 1][j], PD[i][j - 1]);

    Write_Data();
}
