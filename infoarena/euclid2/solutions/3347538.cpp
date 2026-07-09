/*  
    author: qvalentin  
    chr(69) + chr(88) + chr(88)  
    
    
*/

#include <bits/stdc++.h>  
using namespace std;  
#define ull unsigned long long  
#define ll long long  
#define pb push_back  
#define MOD 1000000007  
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);  
int di[4]={0,0,-1,1};  
int dj[4]={-1,1,0,0};  
      
string FILENAME="euclid2";  
ifstream f(FILENAME+".in");  
ofstream g(FILENAME+".out");  

signed main(){  
    //#define cin f  
    //#define cout g  
    fastio
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;  
        while(b!=0){
            int r=a%b;
            a=b,b=r;
        }
        cout<<b<<'\n';
    }

    
}

