#include <bits/stdc++.h> //JuniorMonster a.k.a Sho10
#define ll long long
#define all(a) (a).begin(), (a).end()
#define sz size
#define f first
#define s second
#define pb push_back
#define er erase
#define in insert
#define mp make_pair
#define pi pair
#define rc(s) return cout<<s,0
#define mod 1000000007
#define PI 3.14159265359
#define CODE_START  ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
using namespace std;
int n,a,b;
FILE*fin=fopen("euclid2.in","r");
FILE*fout=fopen("euclid2.out","w");
int main(){
    fscanf(fin,"%d",&n);
    for(ll i=0;i<n;i++)
    {
           fscanf(fin,"%d",&a);
              fscanf(fin,"%d",&b);
              fprintf(fout,"%d\n",__gcd(a,b));

    }
}
