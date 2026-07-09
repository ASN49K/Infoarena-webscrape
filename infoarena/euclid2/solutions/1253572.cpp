#include <iostream>
#include <fstream>

#define N 100001

using namespace std;

long a,b,t;
int y;
int main()
{
    ifstream myFile;
    myFile.open("euclid2.in");
    myFile >> t;

    ofstream myFilee;
    myFilee.open("euclid2.out");

    for(long i=0; i<t; i++)
    {
        myFile >> a >> b;
        while(b!=0)
        {
            y=b;
            b=a%b;
            a=y;
        }
        myFilee << a << "\n";
    }


    myFile.close();
    myFilee.close();
    return 0;
}
