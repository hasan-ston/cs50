#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int years = 0;
    int startSize, endSize;

    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);
    // TODO: Prompt for start size

    do
    {
        endSize = get_int("End size: ");
    }
    while (startSize > endSize);
    // TODO: Prompt for end size

    while (startSize < endSize)
    {
        startSize = startSize + (startSize / 3) - (startSize / 4); // automatically converts decimal into whole numbers
        years++;
    }
    // TODO: Calculate number of years until we reach threshold

    printf("Years: %i\n", years);
    // TODO: Print number of years
}
