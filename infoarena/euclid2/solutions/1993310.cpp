/*
 * euclid.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: andreir
 */

#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int x,int y){
    if(!y) return x;
    else return cmmdc(y,x%y);
}


int main() {
    int N,x,y;
    for(;N>0;N--){
        in>>x>>y;
        out<<cmmdc(x,y);
    }
    return 0;
}
