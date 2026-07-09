#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream intrareFile;
    ofstream iesireFile;
    intrareFile.open("euclid2.in.txt");
    iesireFile.open("euclid2.out.txt");
    int t,a,b,i;
    intrareFile>>t;
    for(i=1;i<=t;i++)
    {
        intrareFile>>a>>b;
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else b-=a;
        }
        iesireFile<<a<<"\n";
    }
    intrareFile.close();
    iesireFile.close();
    return 0;
}
