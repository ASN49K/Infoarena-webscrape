#include <iostream>
#include <fstream>

using namespace std;
ifstream in("euclid2.in");
    ofstream out("euclid2.out");

int main()
{
int n,i;
    int a,b,c;
    in>>n;

    for(i=1;i<=n;i++){
            in>>a>>b;
    while (b)
        {
    c=a%b;
    a=b;
    b=c;
        }
        out<<a<<"\n";}
    return 0;
}
