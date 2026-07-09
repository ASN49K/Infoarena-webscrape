#include <bits/stdc++.h>
using namespace std;
long long x;
void euclid(int a,int b)
{
    if (a>b){
        a-=b;
        euclid(a,b);
    }
    else if (b>a){
        b-=a;
        euclid(a,b);
    }
    else if (a==b){x=a;}
}
/*void euclid2(int a,int b)//nu-i cel mai bun
{
    int c;
    while (b){
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
void euclid3 (int a,int b,int *d)
{
    if (b==0){
        *d=a;
    }
    else {
        euclid3(b,a%b,d);
    }
}
void euclidExtins(int a,int b,int *d,int *x,int *y)
{
    if (b==0){
        *d=a;
        *x=1;
        *y=0;
    }
    else {
        int x0,y0;
        euclidExtins(b,a%b,d,&x0,&y0);
        *x=y0;
        *y=x0-(a/b)*y0;
    }
}*/
int main()
{
    long long n;
    cin>>n;
    long long s[100003];
    long long c;
    long long a,b;
    for (int i=1;i<=n;i++){
    cin>>a>>b;
    euclid(a,b);
    s[i]=x;
    }
    for (int i=1;i<=n;i++){
        cout<<s[i]<<'\n';
    }
}
