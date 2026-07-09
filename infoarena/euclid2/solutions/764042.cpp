/* 
 * File:   euclid.cpp
 * Author: alex
 *
 * Created on July 3, 2012, 6:31 PM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int euclid(int a, int b)
{
    if(b == 0)
        return a;
    euclid(b, a % b);
}
/*
 * 
 */
int main(int argc, char** argv) {

    fstream f, o;
    f.open("euclid2.in", fstream::in);
    o.open("euclid2.out", fstream::out);
    if(f.fail())
    {
        cout << "Error! File not found!\n";
        return -1;
    }
    
    int n, a, b;
    f >> n;
    for(unsigned int i = 0; i < n; i++)
    {
        f >> a >> b;
        o << euclid(a, b) << endl;
    }
    f.close();
    o.close();
    return 0;
}

