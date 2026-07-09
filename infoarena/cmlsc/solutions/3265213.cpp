#include <fstream>
#include <list>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");


int v[1025], dp[1024][1024];

inline void getArray(const int& n)
{
  for(int i=1; i<=n; i++)
  {
    cin>>v[i];
  }
}

void generateDP(const int& n, const int& m)
{
  int x;

  for(int i=1; i<=m; i++)
  {
    cin>>x;

    for(int j=1; j<=n; j++)
    {
      if(v[j]==x)
        dp[i][j]=max(dp[i-1][j-1]+1, dp[i][j-1]);
      else
        dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    }
  }
  cout<<dp[m][n]<<"\n";
}

list<int> Seq;

void generateSeq(int j, int i)
{
  while(j!=0 && i!=0)
  {
    while(dp[i-1][j]==dp[i][j] && i!=1)
      i--;
    while(dp[i][j-1]==dp[i][j] && j!=1)
      j--;
    if(i==0 || j==0)
      break;

    Seq.push_front(v[j]);
    i--; j--;
  } 
}

inline void printSeq()
{
  for(auto e: Seq)
   cout<<e<<" "; 
}

int main()
{
  ios::sync_with_stdio(false);

  int n, m;
  cin>>n>>m;

  getArray(n);
  generateDP(n, m);
  generateSeq(n, m); 
  printSeq();

  return 0;
}
