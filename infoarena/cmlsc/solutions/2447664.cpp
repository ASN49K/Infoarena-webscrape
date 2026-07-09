#include <fstream>
#include <vector>
#include <math.h>

typedef std::vector<std::vector<int> > Grid;
typedef std::vector<int> Array;
typedef std::pair<int, Array> Solution;

void checkPreviousPositions(Grid &grid, int i, int j) {
  if (j > 0 && grid[i][j - 1] > grid[i][j]) 
    grid[i][j] = grid[i][j - 1];
  
  if (i > 0 && grid[i - 1][j] > grid[i][j]) 
    grid[i][j] = grid[i - 1][j];
}

Array ComputeSubsir(Grid &grid, Array &a, Array &b){
  int i = a.size() - 1, j = b.size() - 1;
  Array subsir;
  while(i >= 0) {
    if (a[i] == b[j]) {
      subsir.push_back(a[i]);
      i--;
      j--;
      continue;
    } 
    if (i <= 0) {
    	i = 0;
    	j--;
    	continue;
	}
	if (j <= 0) {
		j = 0;
		i--;
		continue;
	}
    if (grid[i - 1][j] < grid[i][j - 1]) j--; else i--;
  }
  return subsir;
}

Array cmlsc(Array &a, Array &b) {
  Grid cmlsc(a.size(), std::vector<int>(b.size(), 0));
  
  for(int i = 0; i < a.size(); i++)
    for(int j = 0; j < b.size(); j++) {
    checkPreviousPositions(cmlsc, i, j);
    if (a[i] == b[j]) {
    	cmlsc[i][j] = 1;
    	if (i > 0 && j > 0) cmlsc[i][j] += cmlsc[i - 1][j - 1];
	}
  }
    
  return ComputeSubsir(cmlsc, a, b);
}

int main() {
  freopen("cmlsc.in", "r", stdin);
  freopen("cmlsc.out", "w", stdout);

  int n, m;
  scanf("%d%d", &n, &m);
  Array a(n, 0), b(m, 0);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]);
  for(int i = 0; i < m; i++) scanf("%d", &b[i]);
  if (n < m) swap(a, b);
  Array sol = cmlsc(a, b);
  
  printf("%d\n", sol.size());
  for(int i = sol.size() - 1; i >= 0; i--) printf("%d ", sol[i]);
  
  return 0;
}

