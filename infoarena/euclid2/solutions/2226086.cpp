#include <fstream>

using namespace std;
int main() {

    ifstream inputfile("euclid2.in");
    ofstream outputfile("euclid2.out");

    long number, value1, value2, remaining;
    inputfile >> number;
    for ( int i = 1; i <= number; i++)
    {
        inputfile >>  value1 >> value2;
        remaining = value1 % value2;
        while ( remaining != 0 )
        {
            value1 = value2;
            value2 = remaining;
            remaining = value1 % value2;
        }
        outputfile << value2 << '\n';
    }
    inputfile.close();
    outputfile.close();
    return 0;
}