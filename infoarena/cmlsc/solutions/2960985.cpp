#include <fstream>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int dim = 1030;

int dp[dim][dim] , v[dim] , w[dim] , n , m;

void Reconstruire(int i , int j)
{
	if(i && j)
		{
			if(v[i] == w[j])
				{
					Reconstruire(i-1 , j-1);
					cout << v[i] <<' ';
				}
			else if(dp[i-1][j] > dp[i][j-1])
				Reconstruire(i-1 , j);
			else
				Reconstruire(i , j-1);
		}
}

int main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++i)
		cin >> v[i];
	for(int i = 1 ; i <= m ; ++i)
		cin >> w[i];
	for(int i = n ; i ; --i)
		for(int j = m ; j ; --j)
			if(v[i] == w[j])
				dp[i][j] = dp[i+1][j+1] + 1;
			else
				dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
	cout << dp[1][1] << '\n';
	Reconstruire(n , m);
}
