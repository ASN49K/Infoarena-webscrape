#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX numeric_limits<int>::max()
#define MIN numeric_limits<int>::min()
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int m,n;
    int i,j;
    cin>>m>>n;
    m++;n++;
    int arr[m],brr[n];
    for(i=1;i<m;i++)
        cin>>arr[i];
    for(i=1;i<n;i++)
        cin>>brr[i];
    int sol[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0 || j==0)
                sol[i][j]=0;
            else if (arr[i]==brr[j])
            {
                sol[i][j]=1+sol[i-1][j-1];
            }
            else
            {
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
            }
        }
    }
    /*
    //printing table
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           cout<<sol[i][j]<<"  ";
        }
        cout<<"\n";
    }
    */
    vector<int>ans;
    for(i=m-1,j=n-1;i>0 || j>0;)
    {
        if(sol[i][j]==sol[i-1][j])
        {
            i--;
        }
        else if(sol[i][j]==sol[i][j-1])
        {
            j--;
        }
        else
        {
            ans.push_back(arr[i]);
            i--;j--;
        }
    }
    for(i=ans.size()-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
