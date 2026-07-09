#include<fstream.h>   
ifstream f("euclid2.in");   
ofstream g("euclid2.out");   
int x,y;   
int euclid(int a,int b)   
{while(b)   
    {int r=a%b;a=b;b=r;}   
return a;   
}   
int main()   
{   
f>>x>>y;   
g<<euclid(x,y);   
return 0;   
}  
