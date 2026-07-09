#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int N , A , B ;

    in >> N;

    while ( N-- )
    {
         in >> A >> B;


         int R = A % B;

         while ( R != 0 )
         {
             A = B ;
             B = R;
             R = A%B;
         }

         out << B <<"\n";
    }
}
