#include<fstream>
#include<limits.h>
#include<iostream>
using namespace std;

int main()
{
    fstream f;
    fstream g;
    f.open("euclid2.in",ios::in);

    g.open("euclid2.out",ios::out);
    int n;
    f>>n;
    int x,y;
    for(int i=0;i<n;i++)
    {
        f>>x>>y;int min,max;
        if(x>y){min=y;max=x;}
        else{min=x,max=y;}
        while(max%min!=0)
        {
            int aux=max-((int)(max/min))*min;
            max=min;
            min=aux;

        }
        g<<min<<endl;
    }
    f.close();
    g.close();
}
