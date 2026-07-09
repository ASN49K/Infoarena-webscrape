//
// Created by Filip on 11/11/2016.
//
#include<iostream>
#include <fstream>
using namespace std;
int A=2 ,B=2;
void eRead()
{
fstream f("euclid2.in");
    f>>A>>B;
    f.close();
}
void eWrite(int answer)
{
    fstream g("euclid2.out");
    g<<answer;
    g.close();
}
void eGetTask()
{
    eRead();
    int R = A % B;
    while(R)
    {
        A =B;
        B =R;
        R =A % B;
    }
    if(B!= 1)
    {
        eWrite(B);
    }
}
int main()
{
    eGetTask();
    return 0;
}
