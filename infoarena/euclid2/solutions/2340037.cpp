#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    ifstream infile;
    ofstream outfile;
    
    infile.open("euclid2.in");
    outfile.open("euclid2.out");
    
    int rep=0, x=0, y=0, rezultat=0;;
    
    infile >> rep;
    
    if((rep >= 1) && (rep <= 100000))
    {
        for(int i=0; i<rep; i++)
        {
            infile >> x;
            infile >> y;
        
            if((x >= 2) && (y <= 2000000000))
            {
                for(int n=1; n<=y; n++)
                {
                    if((x % n == 0) && (y % n == 0))
                    {
                        rezultat = n;
                    }
                }
                outfile << rezultat << endl;
            }
        }
    }
    
    infile.close();
    outfile.close();

    return(0);
}
