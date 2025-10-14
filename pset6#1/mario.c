#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: "); // Prompt for height
    }
    while (height <= 0 || height >= 9); // until these conditions = FALSE

    // printf("Stored: %i\n", height); // Print a confirmation message

    // for(initialization; condition; update)

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < height - (y + 1); x++)
        {
            printf(" "); // Add space(dots replaced)
        }
        for (int x = 0; x < y + 1; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}

