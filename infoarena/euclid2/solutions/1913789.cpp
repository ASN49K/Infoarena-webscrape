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
    ifstream input;
    input.open("euclid2.in");
    fstream output;
    long long n;
    input>>n;
    long long s[100003];
    long long c;
    long long a,b;
    for (int i=1;i<=n;i++){
    input>>a>>b;
    euclid(a,b);
    s[i]=x;
    }
    input.close();
    output.open("euclid2.out");
    for (int i=1;i<=n;i++){
        output<<s[i]<<'\n';
    }
    output.close();
}
