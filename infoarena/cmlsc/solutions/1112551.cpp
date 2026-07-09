//#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;

ifstream cin("date.in");
ofstream cout("date.out");

#define NMax 1001
int i,j,n,m,q[NMax],dp[NMax][NMax],bst;
char v[NMax],c[NMax];


int main()
{
    cin.getline(v,NMax);
    cin.getline(c,NMax);
    m=strlen(v)-1;
    cout<<m<<'\n';
    n=strlen(c)-1<<'\n';
    cout<<n<<'\n';
    cout<<v<<'\n'<<c;

    /*for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(v[i]==c[j]){
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    i=m;
    j=n;
    for(;i>0;){
        if(v[i]==c[j]){
            q[++bst]=v[i];
            i--;
            j--;
        }
        else if(dp[i][j-1]<dp[i-1][j]){
            i--;
        }else{
            j--;
        }
    }
    cout<<bst;

    for(i=bst;i>0;i++){
        cout<<q[i];
    }*/
    return 0;
}
