#include <iostream>
#include <fstream>

#define N 100001

using namespace std;

long a[N],b[N],t;
int main()
{
    ifstream myFile;
    myFile.open("euclid2.in");
    myFile >> t;
    for(long i=0; i<t; i++)
    {
        myFile >> a[i] >> b[i];
    }

    ofstream myFilee;
    myFilee.open("euclid2.out");

    for(long i=0; i<t; i++)
    {
        while(a[i]!=b[i])
        {
            if(a[i]>b[i])
            {
                a[i]=a[i]-b[i];
            }
            else
            {
                b[i]=b[i]-a[i];
            }
        }
        myFilee << a[i] << "\n";
    }

    myFile.close();
    myFilee.close();
    return 0;
}
