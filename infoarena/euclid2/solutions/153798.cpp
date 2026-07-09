#include<fstream.h>   
int euclid(int a, int b)   
    {   
    int r;   
    r=a%b;   
    while(r)   
        {   
        a=b;b=r;r=a%b;   
        }   
    return b;   
    }   
int main()   
    {   
    int a,b,n;   
    ifstream f("euclid2.in");   
    ofstream g("euclid2.out");
    f>>n;
	for(int i=1;i<=n;i++){   
    f>>a>>b;   
    g<<euclid(a,b)<<"\n";}   
    f.close();   
    g.close();   
    return 0;   
    }   