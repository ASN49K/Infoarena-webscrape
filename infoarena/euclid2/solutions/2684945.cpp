#include <cstdio>


int gcd_division(int a, int b)
{
    if(a == 0 || b == 0)
        return 0;

    int t;

    while(b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }

    return a;
}
    

int main(void)
{
	int T, A, B;
	int i;

	const char *input_file = "euclid2.in";
	const char *output_file = "euclid2.out";

	FILE *input_stream;
	FILE *output_stream;

	input_stream = fopen(input_file, "r");
	output_stream = fopen(output_file, "w");

	// iterate T pairs of A and B numbers
	for (fscanf(input_stream, "%d", &T); T; --T)
	{
		// read the next pair
        fscanf(input_stream, "%d %d", &A, &B);

        // gcd_division(A, B) is called
        fprintf(output_stream ,"%d\n", gcd_division(A, B));
	}

    fclose(output_stream);
    fclose(input_stream);

    return 0;
}