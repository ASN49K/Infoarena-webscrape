#include<iostream.h>
#include <fstream.h>
int eucl(int a, int b)
{
    if(a==b) return a;
    if(a>b)
           return eucl(a-b,b);
    else
        return eucl(a,b-a);
}
int main()
{
    int n,a[2][100];
    ifstream fisin("euclid.in");
    fisin>>n;
    ofstream fisout("euclid.out");
    for(int i=1;i<=n;i++)
            {
                        fisin>>a[1][i];
                        fisin>>a[2][i];
                        fisout<<eucl(a[1][i],a[2][i])<<endl;
            }
    
    fisin.close();   
   fisout.close();
}
