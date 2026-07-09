// cmlsc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1026],b[1026],d[1026][1026],sir[1026];
int main()
{
    int n,m;
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>a[i];
    for(int j=1; j<=n; j++)
        cin>>b[j];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
    int ind=0;
    int i=m,j=n;
    while(i)
        if(a[i]==b[j])
            sir[++ind]=a[i],i--,j--;
        else if(d[i-1][j]<d[i][j-1])
            j--;
        else i--;
    cout<<ind<<'\n';
    for(int i=ind; i>=1; i--)
        cout<<sir[i]<<" ";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
