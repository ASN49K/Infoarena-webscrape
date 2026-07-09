#include<bits/stdc++.h>

#define rep(i,a,b) for(int i=int(a); i<=int(b); ++i)
#define rev(i,b,a) for(int i=int(b); i>=int(a); --i)
#define rec(i,a,b,c) for(int i=int(a); i<=int(b); i+=int(c))
#define recv(i,a,b,c) for(int i=int(a); i>=int(b); i-=int(c))
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define all(c) c.begin(), c.end()
#define tr(container, it) for(auto it=(container).begin(); it != (container).end(); ++it)
#define sqr(x) ((x)*(x))
#define sz(a) int((a).size())
#define mod(a,n) ((a) < 0 ? ((n)+(a)) : ((a)%(n)))
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;

void LCS(const vector<int>& A, const vector<int>& B, vector<int> res){
  // dp[i][j] = LCS for A(0..i) and B(0..j)
  // Base case: dp[0][j] = 1 if A(0) is in B(0..j)
  // Similar with dp[i][0].
  // Update rule: dp[i][j] = max(A(i) == B(j) ? 1 + dp[i-1][j-1] : 0, max(dp[i][j-1], dp[i-1][j]))
  vector<vector<int> > opt(A.size(), vector<int>(B.size(),0));


  // Update rule, we take care of the base case here too.
  for(int i=0; i<A.size(); ++i)
    for(int j=0; j<B.size(); ++j)
      opt[i][j] = A[i] == B[i] && i && j ? 1 + opt[i-1][j-1] : max(i ? opt[i-1][j] : 0, j ? opt[i][j-1] : 0);


  res.clear();
  for(int i=A.size()-1, j=B.size()-1; i>=0 && j>=0;){
    if(A[i] == B[j]){
      res.push_back(A[i]);
      i--;
      j--;
    }
    else if(i && opt[i-1][j] + 1 == opt[i][j]){
      i--;
    }
    else if(j && opt[i][j-1] + 1 == opt[i][j]){
      j--;
    }
  }
  reverse(begin(res), end(res));
}



int main(){

  // read data
  ifstream fin("cmlsc.in");
  ofstream fout("cmlsc.out");

  int m,n;
  fin >> m >> n;
#if 1
  vector<int> A(m,0);
  vector<int> B(n,0);
  rep(i,0,m-1)
    fin >> A[i];
  rep(i,0,n-1)
    fin >> B[i];
  vector<int> res;
  LCS(A,B,res);
  for(int i=0; i<res.size(); ++i)
    fout << res[i] << " ";
#else
  vector<int> A(m+1,0);
  vector<int> B(n+1,0);
  rep(i,1,m)
    fin >> A[i];
  rep(i,1,n)
    fin >> B[i];
  // compute length of longest common subsequence
  vector<vector<int> > opt(m+1, vector<int>(n+1,0));
  rep(i,1,m)
    rep(j,1,n)
      opt[i][j] = (A[i] == B[j] ? opt[i-1][j-1]+1 : max(opt[i-1][j], opt[i][j-1]));
  fout << opt[m][n] << endl;

  // compute the sequence
  vector<int> seq;
  int i,j;
  for(i=m, j=n; j>=1 && i>=1;)
    if(A[i] == B[j])
      seq.push_back(A[i]), i--, j--;
    else if(opt[i-1][j] < opt[i][j-1])
      j--;
    else
      i--;
  rev(i,seq.size()-1,0)
    fout << seq[i] << " ";
#endif

  return 0;
}
