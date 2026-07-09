#include <iostream>
#include <fstream>


using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,m,j;
    in>>j;

    for(int i=1;i<=j;i++)
{
    in>>n>>m;

    if(n<m)
        swap(n,m);

    while(n%m!=0)
    {
         if(n<m)
            swap(n,m);

        n=n%m;


    }
        out<<m<<endl;
}
    in.close();
    out.close();
    return 0;
}
