// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 5000; // <-bucket size

// Hash table
node *table[N];

unsigned int word_count = 0; // to use for the size function later on

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    int index = hash(word); // hasing the word to obtain hash value
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false; // null
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // utlizing the entire word instead of just the first character of the word --> more robust
    unsigned long total = 0; // non negative values
    for (int i = 0; i < strlen(word); i++)
    {
       c total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    for (int i = 0; i < N; i++)
    { // setting all the index's of nodes to null
        table[i] = NULL;
    }
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Cannot open");
        return false;
    }

    // Read words from dictionary file
    char buffer[45];
    while (fscanf(file, "%s", buffer) != EOF) // end of file
    {
        node *word2 = malloc(sizeof(node)); // allocating memory
        int hash_value = hash(buffer);
        strcpy(word2->word, buffer);
        word2->next = table[hash_value]; // next node pointing to the previous one
        table[hash_value] = word2;       // hash table pointing to the new word
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *temp = table[i];
        node *cursor = table[i];

        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(temp);
            temp = cursor;
        }
    }
    return true;
}
