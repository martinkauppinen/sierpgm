#include <stdio.h>
#include <stdlib.h>

/* simple power function for image size */
unsigned int ipow(unsigned int base, unsigned int exp)
{
    unsigned int result = 1;
    while(exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Incorrect number of arguments.\n");
        printf("Provide one (1) argument (the number of iterations).\n");
        exit(0);
    }    

    const unsigned int iterations = atoi(argv[1]);
    const unsigned int width = ipow(2, iterations);
    const unsigned int height = width;
    unsigned int i, j;
    FILE *f = fopen("sierpinski.pgm", "wb");
    (void) fprintf(f, "P5\n%d %d\n1\n", width, height);

    for (j = 0; j < height; j++)
    {
        for (i = 0; i < width; i++)
        {
            static unsigned char pixel;
            pixel = (i & j) ? 1 : 0;
            (void) fwrite(&pixel, 1, 1, f);
        }
    }

    (void) fclose(f);
    return 0;
}
