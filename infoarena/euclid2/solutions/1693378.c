#include <stdio.h>

long cmmdc(long first, long second);

int main() {
  FILE *input, *output;
  long count, first, second, result;

  input  = fopen("euclid2.in",  "r");
  output = fopen("euclid2.out", "w");

  fscanf(input, "%ld\n", &count);

  for(long index = 0; index < count; index += 1) {
    fscanf(input, "%ld %ld\n", &first, &second);

    result = cmmdc(first, second);

    fprintf(output, "%ld\n", result);
  }

  fclose(input);
  fclose(output);

  return 0;
}

long cmmdc(long first, long second) {
  long reminder = 0;

  while (second) {
    reminder = first % second;
    first    = second;
    second   = reminder;
  }

  return first;
}
