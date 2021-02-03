#include <stdio.h>
#include <stdlib.h>

//Binary Search implementation for int arrays

int binsearch_rec(int[], int, int, int);



int binsearch(int arr[], int num, int len);
/* arr - Array to be searched
   num - number to look for
   len - size of the array  */



int * random_arr(){
    static int array[10];
    int i;
    int prev_number = 0;
    for (i=0; i<10; i++) {
        array[i] = (rand() % 100) + prev_number ;
        prev_number = array[i];
    }
    return array;
}
int main(){
    // Example of array implementation
    int sorted_arr[] = {83, 169, 246, 261, 354, 389, 475, 567, 899, 1000, 15000};
    int test = binsearch(sorted_arr, 15000, sizeof(sorted_arr)/sizeof(sorted_arr[0]));
    printf("The index is: %d", test); // The index is 10
}

int binsearch_rec(int array[], int num, int start, int end) {
    int middle = (start + end)/2;

    if (array[middle] == num) {
        return middle;
    }
    else {
        if (start >= end && start != num){
        return -1;
        }
        if (array[middle] > num) {
            return binsearch_rec(array,num, 0, middle - 1);
        }
        else if (array[middle] < num) {
            return binsearch_rec(array, num, middle+1, end);
        }

    }

}

int binsearch(int arr[], int num, int len){
    int start = 0;
    int end = len;
    int m = (start + end) / 2;
    return binsearch_rec(arr, num, start, end);
}
