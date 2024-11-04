#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Define the maximum size of the array

// Function prototypes
void insert(int arr[], int *size, int element, int position);
void delete(int arr[], int *size, int position);
int search(int arr[], int size, int element);
void update(int arr[], int size, int position, int newElement);
void display(int arr[], int size);

int main(){
    int arr[MAX_SIZE]; // Initialize the array
}

void insert(int arr[], int *size, int element, int position){
    if(*size >= MAX_SIZE){
        printf("Array is full. Cannot insert element.\n");
        return;
    }

    if(position < 0 || position > *size){
        printf("Invalid position.\n");
        return;
    }

    //Shift elements to the right to create space for new elements
    for(int i = *size; i > position; i--){
        arr[i] = arr[i - 1];
    }
    arr[position] = element; //insert the new element
    (*size)++; //Increment the size of the array
}

void delete(int arr[], int *size, int position){
    if(*size <= 0){
        printf("Array is empty. Cannot delete element.\n");
        return;
    }
    if(position < 0 || position >= *size){
        printf("Invalid position.\n");
        return;
    }
    //Shift elements to the left to fill the space of the deleted element
    for(int i = position; i < *size - 1; i++){
        arr[i] = arr[i + 1];
    }
    (*size)--; //Decrement the size of the array
}

int search(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i; 
        }
    }
    return -1; //Return -1 if the element is not found
}

//Function to update an element at a specified position
void update(int arr[], int size, int position, int newElement){
    if(position < 0 || position >= size){
        printf("Invalid position.\n");
        return;
    }
    arr[position] = newElement;
}

//Function to display the elements of the array
void display(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}