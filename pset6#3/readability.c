#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_sentences(string text);
int count_words(string text);
int calculate_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int sentences = count_sentences(text);
    int words = count_words(text);
    int index = calculate_index(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text) // Counting letters
{
    int count = 0;
    for (int i = 0; ltrs = strlen(text); i < ltrs; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text) // counting sentences
{
    int count = 0;
    for (int i = 0, sntcs = strlen(text); i < sntcs; i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            count++;
        }
    }
    return count;
}

int count_words(string text) // Counting words
{
    int count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count + 1; // Add 1 for the last word
}


int calculate_index(int letters, int words, int sentences) // Calculating grade lvl
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}
