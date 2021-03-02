#include "ArrayList.h"

ArrayList al_create(int initialSize){
    ArrayList new = malloc(sizeof(struct arraylist));
    if(new == NULL){
        //check for allocation
        exit(1);
    }

    new->size = 0;
    new->con = malloc(sizeof(int) * initialSize);
    if(new->con == NULL){
        //check for allocation
        exit(1);
    }
    
    return new;
}

ArrayList al_create(){
    return al_create(50);
}

void al_destroy(ArrayList toDel){
    free(toDel->con);
    free(toDel);
}

void al_add(ArrayList this, int val){
    //TODO: resize me
    al_set(this, this->size - 1, val);
    this->size++;
}

int al_get(const ArrayList this, int index){
    if(index < 0 || index > this->size){
        exit(1);
    }

    return this->con[index];
}

int al_remove(ArrayList this, int index){
    int temp = this->con[index];
    this->con[index] = 0;
    for(int *i = this->con + index + 1; i <= this->con + this->size - 1; i++){
        //from index + 1 to last index
        *(i - 1) = *i;
    }
    this->size--;
    return temp;
}

void al_set(ArrayList this, int index, int val){
    this->con[index] = val;
}

void al_clear(ArrayList this){
    for(int i = 0; i < this->size; i++){
        //for every index
        this->con[i] = 0;
    }  
}

int al_size(const ArrayList this){
    return this->size;
}