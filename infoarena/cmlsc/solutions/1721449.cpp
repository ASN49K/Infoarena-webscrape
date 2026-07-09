#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int M, N, A[1025], B[1025], i, j, l, C[1025], k, ok;
int main()
{f>>M>>N;
for(i=1; i<=M; i++)
    f>>A[i];
for(j=1; j<=N; j++)
    f>>B[j];
i=k=1;
while(i<=M)
    {ok=0;
    for(j=k; j<=N; j++)
        if(A[i]==B[j])
            {l++;
            ok=1;
            C[l]=A[i];
            break;}
    if(ok==1)
        k=j+1;
    i++;
}
g<<l<<endl;
for(i=1; i<=l; i++)
    g<<C[i]<<" ";
    return 0;
}
