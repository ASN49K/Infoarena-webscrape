#include<fstream>
#include<cstring>

using namespace std;


int as, bs, ss=0;
int a[1026], b[1026], sol[1024];
int d[1026][1026], dir[1026][1026];


int main(void) {
  freopen("cmlsc.in", "rt", stdin);
  freopen("cmlsc.out", "wt", stdout);

  scanf("%d %d", &as, &bs);
  for (int i=1; i<=as; ++i)
    scanf("%d", &a[i]);
  for (int i=1; i<=bs; ++i)
    scanf("%d", &b[i]);

  memset(d, 0, sizeof(d));
  for (int i=1; i<=as; ++i)
    for (int j=1; j<=bs; ++j) {
      d[i][j] = max(max(d[i-1][j], d[i][j-1]), a[i]==b[j] ? d[i-1][j-1]+1 : 0);
      if (a[i] == b[j] && d[i-1][j-1]+1 == d[i][j])
        dir[i][j] = 0;
      else if (d[i-1][j] == d[i][j])
        dir[i][j] = 1;
      else dir[i][j] = 2;
    }

  printf("%d\n", d[as][bs]);

  for (int i=as, j=bs; i>0 && j>0;) {
    if (dir[i][j] == 0) {
      sol[ss++] = a[i];
      --i;
      --j;
    } else if (dir[i][j] == 1) {
      --i;
    } else {
      --j;
    }
  }
  for (int i=ss-1; i>0; --i)
    printf("%d ", sol[i]);
  printf("%d\n", sol[0]);

  return 0;
}
