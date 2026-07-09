//
//  main.cpp
//  Euclid
//
//  Created by Anca Tache on 03/12/2017.
//  Copyright © 2017 Anca Tache. All rights reserved.
//

#include <iostream>
#include <fstream>

int Euclid(int x, int y)
{
    if(x%y==0) return y;
    else return Euclid(y,x%y);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n,x,y,z;
    std::ifstream f;
    std::ofstream g;
    f.open("euclid2.in");
    g.open("euclid2.out");
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>x>>y;
        z=Euclid(x,y);
        g<<z<<"\n";
    }
    f.close();
    g.close();
    return 0;
}
