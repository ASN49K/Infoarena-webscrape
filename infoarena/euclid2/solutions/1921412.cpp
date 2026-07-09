#include<bits/stdc++.h>
using namespace std;
int a,b,t;
 
int cmd(int a,int b)
    {
    if(!b)
        return a;
    return cmd(b,a%b);
    }
 
int main()
    {
    int i;
    ifstream cin("euclid2.in"); 
	ofstream cout("euclid2.out");
    cin>>t;
    for(i=1;i<=t;i++)
        {
        cin>>a>>b;
        cout<<cmd(a,b)<<endl;
        }
 
    return 0;
    }
