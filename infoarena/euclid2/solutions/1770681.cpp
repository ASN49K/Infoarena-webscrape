#include <iostream>
#include <fstream>

using namespace std;

int Euclid(int x,int y)
{
    int r;
    while(y){r=x%y;x=y;y=r;}
    return x;
}

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,x,y;
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>x>>y;
        out<<Euclid(x,y)<<"\n";
    }
in.close();
out.close();
    return 0;
}
