#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 

} 

int main()
{
    ifstream inputfile;
    inputfile.open("euclid2.in"); 

    ofstream outputfile;
    outputfile.open("euclid2.out");

    int n, a, b;

    inputfile >> n;
    for(int i=0; i<n; i++){
        inputfile >> a >> b;
        outputfile << gcd(a, b) << "\n";

    }
    
    inputfile.close();
    outputfile.close();


}