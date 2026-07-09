#include <stdio.h>

int main()
{
    FILE *read = fopen("euclid2.in", "r");
    FILE *write = fopen("euclid2.out", "w");

    int number_of_pairs = 0, member1, member2;

    fscanf(read, "%d", &number_of_pairs);

    for (int i = 0; i < number_of_pairs; ++i)
    {
        fscanf(read, "%d%d", &member1, &member2);

        while (member2)
        {
            int c = member1 % member2;
            member1 = member2;
            member2 = c;
        }


        fprintf(write, "%d\n", member1);
    }
    fclose(read);
    fclose(write);
    return 0;
}
