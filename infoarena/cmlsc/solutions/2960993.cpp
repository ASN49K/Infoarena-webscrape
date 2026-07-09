#include <fstream>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

const int dim = 1030;

int dp[dim][dim] , v[dim] , w[dim] , n , m , rsp[300] , k;

void Reconstruire(int i , int j)
{
	while(i && j)
		{
			if(v[i] == w[j])
				{

					rsp[++k] = v[i];
					i-- , j--;
				}
			else if(dp[i-1][j] > dp[i][j-1])
                i--;
			else
				j--;
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
	for(int i = k ; i; --i)
            cout << rsp[i] <<' ';
}
