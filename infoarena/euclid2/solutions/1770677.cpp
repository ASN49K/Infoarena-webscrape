#include <iostream>
#include <fstream>

using namespace std;

int Euclid(int x,int y)
{

    while(x!=y)
    {
        if(x>y)
            x=x-y;
        else
            y=y-x;
    }
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
        out<<Euclid(x,y)<<endl;
    }
in.close();
out.close();
    return 0;
}
