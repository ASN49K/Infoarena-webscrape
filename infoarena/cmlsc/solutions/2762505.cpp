#include <iostream>
#include <fstream>

using namespace std;

int main()
{unsigned A[1025], B[1025], C[1025];
int M, N, i, j, ok, nr=0;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

f>>M>>N;
for(i=1; i<=M; i++)
    f>>A[i];

for(i=1; i<=N; i++)
    f>>B[i];

for(i=1; i<=M; i++)
{j=1; ok=0;
while(j<=N && ok==0)
    {if(A[i]==B[j])
{   nr++;
    C[nr]=A[i];
    ok=1;
}
    j++;}
}
f.close();
g<<nr<< "\n";
for(i=1; i<=nr; i++)
    g<<C[i]<<' ';
g.close();
    return 0;
}
