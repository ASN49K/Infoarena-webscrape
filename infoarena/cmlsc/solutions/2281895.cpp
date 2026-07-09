#include <iostream>

using namespace std;
int A[256],B[256],n,m,i,j,nr=0;
int main()
{
    cin>>m>>n;
    for(i=1;i<=m;i++)
        cin>>A[i];
    for(j=1;j<=n;j++)
        cin>>B[j];
        if(m>n){
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(A[i]==B[j] && i>=j){
        nr++;
        cout<<A[i]<<" ";
        }
        cout<<nr;}
        else
            if(m<=n){
                   for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(A[i]==B[j] && i<=j){
        nr++;
        cout<<A[i]<<" ";
        }
        cout<<nr;}


    return 0;
}
