#include <iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<cstdlib>
#include<ctype.h>
#include<iomanip>
#define ll long long
#define st string
  
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

long gcd(long a,long b)
{
  if(b==0)
    return a;
  return gcd(b,a%b);
}
 
vector<string>res;
 
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int counter = 0;
    int contor = 0;
    for(int i=0;i<n;i++)
    {
        if('0' < s[i] && s[i] <='9')
        {
            counter = counter + s[i]-'0';
            contor++;
        }
    }

    if('0' < s[n-1] && s[n-1] <= '9')
        contor--;

    cout<<counter + contor<<'\n';
}

int verificare(st s)
{
    bool ok = true;
    for(int i=1;i<s.size() && ok == true;i++)
    {
        if('a' <= s[i] && s[i] <= 'z')
            ok = false;
    }

    if(ok == true)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(0);
    int T;
    fin>>T;
    long a,b;
    while(T--)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}

