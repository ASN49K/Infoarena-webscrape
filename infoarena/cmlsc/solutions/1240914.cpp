#include <cstdio>

#define NMAX 1030
#define max(a, b) (a > b ? a : b)

using namespace std;

int N, M;
int v1[NMAX], v2[NMAX], table[NMAX][NMAX];

void read()
{
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d%d", &N, &M);
  for(int i = 1; i <= N; i++)
    scanf("%d", &v1[i]);

  for(int i = 1; i <= M; i++)
    scanf("%d", &v2[i]);
}

void solve()
{
  for(int i = 1; i <= N; i++)
  {
    for(int j = 1; j <= M; j++)
    {
      table[i][j] = max(table[i-1][j], table[i][j-1]);
      if(v1[i] == v2[j] && table[i][j] == table[i-1][j-1])
        table[i][j] = table[i-1][j-1] + 1;
    }
  }
}

void printSolution()
{

  int m = table[N][M], solution[m], i = N, j = M;
  printf("%d\n", m);
  while(i && j)
  {
    if(v1[i] == v2[j])
    {
      solution[m] = v1[i];
      m--;
      i--;
      j--;
    }
    else if(table[i][j] == table[i-1][j])
      i--;
    else
      j--;
  }

  m = table[N][M];
  for(int i = 1; i <= m; i++)
    printf("%d ", solution[i]);
}

int main() {
  read();
  solve();
  printSolution();
  return 0;
}
