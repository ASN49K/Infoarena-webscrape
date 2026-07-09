#include <cstdio>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Solver {
private:
  vector<int> A, B;
  vector<vector<int>> DP;
  int N, M;
public:
  Solver() {
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
  }
  ~Solver() {
    fclose(stdin);
    fclose(stdout);
  }
  void readData() {
    scanf("%d%d", &N, &M);
    A.resize(N+1);
    B.resize(M+1);
    DP.resize(N+1,vector<int>(M+1, 0));
    for (int i = 1; i <= N; ++i)
      scanf("%d", &A[i]);
    for (int i = 1; i <= M; ++i)
      scanf("%d", &B[i]);
  }
  void calculate() {
    for (int i = 1; i <= N; ++i)
      for (int j = 1; j <= M; ++j)
	if (A[i] == B[j])
	  DP[i][j] = max(DP[i][j], DP[i-1][j-1] + 1);
	else
	  DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
  }
  void printSolution()
  {
    printf("%d\n", DP[N][M]);
    int toPrint = DP[N][M];
    int i = N, j = M;
    vector<int> solution;

    while (toPrint) {
      if (A[i] == B[j]) {
	solution.emplace_back(A[i]);
	--i; --j; --toPrint;
      }
      else
	if (DP[i-1][j] > DP[i][j-1])
	  --i;
	else
	  --j;
    }
    reverse(solution.begin(), solution.end());
    for (auto it: solution)
      printf("%d ", it);
    printf("\n");
  }
  void printData() {
    for (auto it: A)
      printf("%d ", it);
    printf("\n");
    for (auto it: B)
      printf("%d ", it);
    printf("\n");
    for (auto it: DP) {
      for (auto jt: it) 
	printf("%d ", jt);
      printf("\n");
    }
  }
};

int main()
{
  unique_ptr<Solver> s = make_unique<Solver>();
  s->readData();
  s->calculate();
  //  s->printData();
  s->printSolution();
  
  return 0;
}
