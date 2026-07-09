#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

const int nmax = 1025;
int dp[nmax][nmax];
vector<int> solve(const vector<int>& A, const vector<int>& B)
{
	int lena = A.size();
	int lenb = B.size();
	
	memset(dp, 0, sizeof(dp));
	for(int i = 1;i <= lena;++i)
	{
		for(int j = 1;j <= lenb;++j)
		{
			if(A[i - 1] == B[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	
	vector<int> ans;
	int i = lena, j = lenb;
	int max_len = dp[lena][lenb];
	while(i >= 1 && j >= 1)
	{
		if(A[i - 1] == B[j - 1])
		{
			ans.push_back(A[i - 1]);
			--max_len;
			--i, --j;
		}
		else
		{
			if(dp[i - 1][j] == max_len)
			{
				--i;
			}
			else
			{
				--j;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	
	int n, m;
	in >> n >> m;
	vector<int> A(n);
	vector<int> B(m);
	
	for(int i = 0;i < n;++i)
	{
		in >> A[i];
	}
	for(int i = 0;i < m;++i)
	{
		in >> B[i];
	}
	
	vector<int> sol = solve (A, B);
	out << sol.size() << "\n";
	int len = sol.size();
	
	for(int i = 0;i < len - 1;++i)
	{
		out<<sol[i]<<" ";
	}
	if(len > 0)
	{
		out<<sol[len - 1];
	}
	out<<"\n";
	in.close();
	out.close();
}
