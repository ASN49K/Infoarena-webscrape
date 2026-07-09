// Alg. lui Euclid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <cstdio>
FILE* f,*g;
int x, y, n, resolution;
int Euclid(int a, int b)
{
    if (!b) return a;
    return Euclid(b, a % b);
}
int main()
{
    f = fopen("euclid.in", "r");
    g = fopen("euclid.out", "w");
    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fscanf(f, "%d%d", &x, &y);
        fprintf(g, "%d\n", Euclid(x, y));
    }
    fclose(f);
    fclose(g);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
