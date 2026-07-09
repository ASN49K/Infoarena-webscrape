///https://infoarena.ro/problema/cmlsc
#include <fstream>
using namespace std;
const int ELMAX = 1024;
int M, N, A[ELMAX], B[ELMAX], SS[ELMAX], maxx, i, j;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int main()
{
    in >> M >> N;
    for (i = 1; i <= M; i++)
        in >> A[i];
    for (i = 1; i <= N; i++)
        in >> B[i];

    for (i = 1; i <= M; i++)
        for (j = 1; j <= N; j++)
            if (A[i] == B[j]){
                maxx++;
                SS[maxx] = A[i];
            }

    out << maxx << '\n';
    for (i = 1; i <= maxx; i++)
        out << SS[i] << ' ';

    in.close();
    out.close();
    return 0;
}
