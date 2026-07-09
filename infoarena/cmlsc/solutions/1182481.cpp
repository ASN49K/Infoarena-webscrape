#include <fstream>
#define maxim(a,b) ((a > b) ? a : b)
using namespace std;
const int NMAX=1024;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int M, N, A[NMAX], B[NMAX], D[NMAX][NMAX],BST[NMAX];
int main()
{
    cin>>N>>M;
    int i,j;
    for (i = 1; i <= N; i++)
        cin>>A[i];
    for (i = 1;i <= M; i++)
        cin>>B[i];
    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++ )
         if (A[i] == B[j])
              D[i][j] = D[i-1][j-1] + 1;
           else
             D[i][j] = maxim(D[i-1][j],D[i][j-1]);

 cout<<D[N][M]<<"\n";
 i = N;
 j = M;
 do
 {
     if (A[i]=B[j])
        {BST[D[i][j]] = A[i];
         i--;
         j--; }
      else
        if (D[i][j-1] > D[i-1][j])
            j--;
        else
            i--;
} while (D[i][j]);
  for (i = 1; i <= D[N][M]; i++) cout<<BST[i]<<" ";
 cin.close();
 cout.close();
}
