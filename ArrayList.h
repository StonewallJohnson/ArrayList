#include <stdlib.h>
struct arraylist{
    int size;
    int elements;
    int *con; 
};

typedef struct arraylist *ArrayList;

/**
 * Creates an ArrayList with default size
 **/
ArrayList al_create();

/**
 * Creates an ArrayList with the given initial size
 **/
ArrayList al_create(int);

/**
 * Deallocates an ArrayList
 **/
void al_destroy(ArrayList);

/**
 * Adds the given value to the end of the list
 **/
void al_add(ArrayList, int);

/**
 * Gets the value at the given index
 **/
int al_get(const ArrayList, int);

/**
 * Removes the value at the given index from the list
 **/
int al_remove(ArrayList, int);

/**
 * Sets the given index to the given value
 **/
void al_set(ArrayList, int, int);

/**
 * Clears the list
 **/
void al_clear(ArrayList);

/**
 * Gives the size of the array list
 **/
int al_size(const ArrayList);

/**
 * Takes an old array list and creates
 * a new one with the same elements
 * but double the space
 **/
ArrayList al_resize(ArrayList);

/**
 * Returns a string representation of the
 * array list
 **/
//char *toString(const ArrayList);