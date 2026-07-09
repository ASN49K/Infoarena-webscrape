#include<fstream>
using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

int dp[1025][1025];
int fromX[1025][1025], fromY[1025][1025];

int main()
{
    int n, m;
    int a[1025], b[1025];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int j = 1; j <= m; j++)
        cin >> b[j];
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        { 
            if(a[i] == b[j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                fromX[i][j] = i - 1;
                fromY[i][j] = j - 1;

            }    
            else
            {
                if(dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                    fromX[i][j] = i - 1;
                    fromY[i][j] = j;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                    fromX[i][j] = i;
                    fromY[i][j] = j - 1;
                }
            }
                
        }
    }

    cout << dp[n][m] << "\n";
    int rasp[n], k = 0;
    int currentX = n, currentY = m;
    while(currentX != 0 && currentY != 0)
    {
        int x = currentX, y = currentY;
        if(a[x] == b[y])
        {
            rasp[k] = a[x];
            k++;
        }

        currentX = fromX[x][y];
        currentY = fromY[x][y];
    }

    for(int i = k - 1; i >= 0; i--)
        cout << rasp[i] << " ";
    
    return 0;
}