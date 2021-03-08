#include "ArrayList.h"

ArrayList al_create(int initialSize){
    ArrayList new = (ArrayList) malloc(sizeof(struct arraylist));
    if(new == NULL){
        //check for allocation
        printf("Could not allocate space for ArrayList!");
        exit(1);
    }

    new->size = initialSize;
    new->con = (int *) malloc(sizeof(int) * initialSize);
    if(new->con == NULL){
        //check for allocation
        printf("Could not allocate space for ArrayList!");
        exit(1);
    }

    new->elements = 0;    
    return new;
}

ArrayList al_createDefault(){
    return al_create(50);
}

void al_destroy(ArrayList toDel){
    free(toDel->con);
    free(toDel);
}

void al_add(ArrayList this, int val){
    al_set(this, this->elements, val);
}

int al_get(const ArrayList this, int index){
    if(index < 0 || index > this->size){
        printf("Can not get from that index!");
        exit(1);
    }

    return this->con[index];
}

int al_remove(ArrayList this, int index){
    int temp = this->con[index];
    this->con[index] = 0;
    for(int *i = this->con + index + 1; i <= this->con + this->elements - 1; i++){
        //from index + 1 to last index
        *(i - 1) = *i;
    }
    this->elements--;
    return temp;
}

void al_set(ArrayList this, int index, int val){
    if(index >= this->size){
        //need to add more space
        this->con = al_resize(this);
    }
    this->con[index] = val;
    this->elements++;
}

void al_clear(ArrayList this){
    for(int i = 0; i < this->size; i++){
        //for every index
        this->con[i] = 0;
    }  
}

int al_size(const ArrayList this){
    return this->elements;
}

int *al_resize(ArrayList this){
    int *new = malloc(sizeof(int) * this->size * 2);
    for(int i = 0; i < this->elements; i++){
        //for every element in old
        new[i] = this->con[i];
    }
    this->size *= 2;
    free(this->con); 
    return new;
}

// char *toString(const ArrayList this){
//     char *str = malloc(sizeof(char) * this->elements);
//     for(int i = 0; i < this->elements; i++, str++){
//         //for every element in the list
//         *str = this->con[i];
//     }
// }