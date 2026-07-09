#include <iostream>
#include <fstream>

using namespace std;

ofstream g("euclid2.out");
int main()
{
    g << "Hello world!" << endl;
    g.close();
    return 0;
}
