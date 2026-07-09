//
// Created by Filip on 11/11/2016.
//
#include <iostream>
#include <fstream>
using namespace std;
int A;
int Read()
{
    fstream f("C:\\Users\\Filip\\ClionProjects\\C++\\Algo\\Ciur\\Ciur.in");
    f>>A;
    f.close();
}
int Write(int answer)
{
    ofstream g("C:\\Users\\Filip\\ClionProjects\\C++\\Algo\\Ciur\\Ciur.out");
    g<<answer;
    g.close();
}
bool CheckPrim(int a)
{
    cout<<"v";
    int k = 0;
for(int i = 1;i<=a;i++)
    {
        if(a%i== 0)
        {
            k++;
        }
    }
    return k==2;
}
int GetTask()
{
    Read();
    int nr =0;
    for(int i =1;i<= A;i++)
    {
        if(CheckPrim(i))
        {
            nr++;
        }
    }
    Write(nr);
}
int main()
{
    GetTask();
    return 0;
}