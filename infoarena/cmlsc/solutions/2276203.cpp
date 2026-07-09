#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAXN 1025

int dp[MAXN][MAXN];
char n[MAXN], m[MAXN], ret[MAXN];
int nl,ml, bst;

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);
  scanf("%d %d",&nl, &ml);
  
  for (int i = 0; i < nl; ++i) {
    scanf("%d",&n[i]);
  }
  
  for (int i = 0; i < ml; ++i) {
    scanf("%d", &m[i]);
  }
  
  for (int i = 0; i <= nl; ++i) {
    dp[i][0] = 0;
  }
  
  
  for (int i = 0; i <= ml; ++i) {
    dp[0][i] = 0;
  }
  
  bst = 0;
  
  for (int i = 1; i <= nl; ++i) {
    for (int j = 1; j <= ml; ++j) {
      if (n[i - 1] == m[j - 1]) {
        dp[i][j] = 1 + dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
      }
    }
  }
  
  int i = nl;
  int j = ml;
  
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i][j-1]) {
      j -= 1;
    } else if (dp[i][j] == dp[i-1][j]) {
      i -= 1;
    } else {
      ret[bst++] = n[i-1];
      i -= 1;
      j -= 1;
    }
  }
  
  printf("%d\n",dp[nl][ml]);
  for (int i = bst - 1; i >= 0; --i) {
    printf("%d ",ret[i]);
  }
  
  
  return 0;
}


/* 
Your previous Python 2 content is preserved below:

This is what your interview environment will look like (except in a real interview you will also have audio).

Use the language dropdown near the top right to select the language you would like to use.

You can run code by hitting the 'Run' button, which will appear near the top left once you've selected a language.

There is also a whiteboard you can use for any sketching you need to do. Click on 'Draw' in the bottom center.
 */