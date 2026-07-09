#include <fstream>
#include <vector>
#include <math.h>

typedef std::vector<std::vector<int> > Grid;
typedef std::vector<int> Array;
typedef std::pair<int, Array> Solution;

Array ComputeSubsir(Grid &grid, Array &a, Array &b){
  int i = a.size() - 1, j = b.size() - 1;
  Array subsir;
  while(i > 0) {
    if (a[i] == b[j]) {
      subsir.push_back(a[i]);
      i--;
      j--;
      continue;
    }
    if (grid[i - 1][j] < grid[i][j - 1]) j--; 
	  else i--;
  }
  return subsir;
}

Array cmlsc(Array &a, Array &b) {
  Grid cmlsc(a.size(), std::vector<int>(b.size(), 0));
  
  for(int i = 1; i < a.size(); i++)
    for(int j = 1; j < b.size(); j++) {
	  cmlsc[i][j] = std::max(cmlsc[i - 1][j], cmlsc[i][j - 1]);
    
	  if (a[i] == b[j]) cmlsc[i][j] = cmlsc[i - 1][j - 1] + 1;
    }
    
  return ComputeSubsir(cmlsc, a, b);
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  int n, m;
  scanf("%d%d", &n, &m);
  
  Array a(n + 1, 0), b(m + 1, 0);
  
  for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
  
  for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
  
  Array sol = cmlsc(a, b);
  
  printf("%d\n", sol.size());
  for(int i = sol.size() - 1; i >= 0; i--) 
    printf("%d ", sol[i]);
  
  return 0;
}

