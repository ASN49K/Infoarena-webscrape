#include<fstream>
using namespace std;
#define filein "cmlsc.in"
#define fileout "cmlsc.out"

#define MAX(a,b) ((a > b) ? a : b)

typedef unsigned char byte;

FILE* in,* out;
byte A[1025], B[1025], sir[1025];
int M, N, m[1025][1025], count = 0;
int main()
{
    in = fopen(filein, "r");
    fscanf(in, "%d%d", &M, &N);
    for(int i = 1; i <= M; i++) fscanf(in, "%d", &A[i]);
    for(int i = 1; i <= N; i++) fscanf(in, "%d", &B[i]);
    fclose(in);
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            if(A[i] == B[j])
                m[i][j] = m[i - 1][j - 1] + 1;
            else
                m[i][j] = MAX(m[i][j-1],m[i-1][j]);
        }
    }
    for (int i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++count] = A[i], --i, --j;
        else if (m[i-1][j] < m[i][j-1])
            --j;
        else
            --i;
    out = fopen(fileout, "w");
    fprintf(out, "%d\n", count);
    for(int i = count; i; i--)
        fprintf(out, "%d ", sir[i]);
    fclose(out);
    return 0;
}
