struct arraylist{
    int size;
    int hi[0]; 
};

typedef struct arraylist *ArrayList;

/**
 * Creates an ArrayList
 **/
ArrayList al_create();

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
int al_get(ArrayList, int);

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