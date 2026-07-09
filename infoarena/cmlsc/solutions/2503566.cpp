#include <fstream>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int n,m,v1[1050],v2[1050],dp[1050][1050];
pair< short int, short int>tata[1050][1050];
int val[1050][1050],v[1050];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v1[i];
    }
    for(int i=1;i<=m;i++){
        cin>>v2[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(v1[i]==v2[j]) {
            val[i][j]=v1[i];
			  tata[i][j].first=i;
            tata[i][j].second=j;
		}
        }
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(v1[i]==v2[j]){
                dp[i][j]=dp[i-1][j-1]+1;
                if ( dp[i][j] == 1)
					{tata[i][j].first = i;
					tata[i][j].second = j;
				}
				else {
                tata[i][j].first = tata[i-1][j-1].first;
                tata[i][j].second = tata[i-1][j-1].second;
                
                }val[i][j] = v1[i];


            }
            else {
                if(dp[i-1][j]>dp[i][j-1]){
                    dp[i][j]=dp[i-1][j];
                    tata[i][j].first=tata[i-1][j].first;
                    tata[i][j].second=tata[i-1][j].second;

                }
                else{
                    dp[i][j]=dp[i][j-1];
                    tata[i][j].first=tata[i][j-1].first;
                    tata[i][j].second=tata[i][j-1].second;


                }
        }
    }
    cout<<dp[n][m]<<'\n';
    int cnt=0,i=n,j=m;
    while(cnt<dp[n][m]){
        if (v1[i] == v2[j]) {
        v[++cnt]=val[i][j];

        }i=tata[i][j].first;
        j=tata[i][j].second;
    }
    for(int i=cnt;i>0;i--){
        cout<<v[i]<<" ";
    }
    return 0;
}
