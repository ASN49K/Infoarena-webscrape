#include<bits/stdc++.h>
#define ll long long

using namespace std;

FILE *in = fopen("euclid2.in","r");
FILE *out = fopen("euclid2.out","w");


int euclid(int a,int b)
{
    while(b)
    {
        if(a>b)
            a-=b;
        else
            b-=a;
    }
    return a;
}
void readsolve()
{
    int t;
   fscanf(in,"%d",&t);
  cin>>t;
    while(t)
    {
        int a,b;
       fscanf(in,"%d %d",&a,&b);
        fprintf(out,"%d %d\n",euclid(a,b));

        t--;
    }
}

int main()
{
    readsolve();
}
