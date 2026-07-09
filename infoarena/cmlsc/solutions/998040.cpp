#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
char c[100];
int m=0;
int a[10000][10000];
char s[1025],s2[1025];
char v[1000];

int maxim(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int lcs(char* x , char* b,int i,int j)
{

if (i==0 || j==0)
{
    return 0;
}

 else if(x[i]==b[j])
 {
     // c[++a]=x[i];
    // cout<<c[a];

    if(a[i][j]!=0)
    {
       a[i][j]= lcs(x,b,i-1,j-1)+1;


        return a[i][j];

    }
       else
       {

           m=m+1;
        v[m]=x[i];


        a[i][j]= lcs(x,b,i-1,j-1)+1;


        return a[i][j];
        }
 }
else
{
    if(a[i-1][j]&&a[i][j-1]!=0)
    {
        return maxim(a[i][j-1],a[i-1][j]);
    }
    else
    {a[i][j-1]=lcs(x,b,i,j-1);
    a[i-1][j]=lcs(x,b,i-1,j);


       return maxim(a[i][j-1],a[i-1][j]);
    }
}

}
int main()
{   int n1,n2,l1,l2,i,j;
char ch;
    f>>n1;
    f>>n2;
    for(i=0;i<n1;i++)
    {
        f>>ch;
        s[i]=ch;
    }
    for(i=0;i<n2;i++)
    {
        f>>ch;
        s2[i]=ch;


    }



     l1=strlen(s);
     l2=strlen(s);





//cout<<s2[0];
    i=lcs(s,s2,l1,l2);

g<<i-1<<"\n";
for(i=1;i<=m;i++)
{
    if(v[i]==' ')
;
        else
    g<<v[i]<<" ";
}

}

