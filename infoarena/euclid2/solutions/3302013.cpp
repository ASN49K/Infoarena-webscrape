#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");

    int T;
    fin >> T;

    string line;
    while (getline(fin, line))
    {
        if (line.empty()) continue;        

        int a, b;
        stringstream ss(line);
        ss >> a >> b;


        fout << gcd(a, b) << endl;
    }

    return 0;
}