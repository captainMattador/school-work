/*--------------------------------------------------------------------
 Title: Lab 6 - Programming Assignment (Sorting Algorithm 2) - Bozelka
 File: Driver for the Assignment
 Abstract: In this assignment a new algorithm called CoolSort is used.
 In the algorithm a sequences is supplied and used to break an array
 into smaller subsets that get sorted first. By the final sequence
 the entire array will be sorted.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 02/12/2016
 --------------------------------------------------------------------*/


#include <iostream>
using namespace std;

void CoolSort(int arr[], int arrSize, int sequence[], int sequenceSize);
void printArray(int arr[], int size);

int main(int argc, const char * argv[]) {

    const int ARRAY_SIZE = 11;
    const int SEQUENCE_SIZE = 3;
    
    int H[SEQUENCE_SIZE] = {5, 2, 1};
    int sortArr[ARRAY_SIZE] = {2, 5, 9, 4, 10, 7, 8, 1, 11, 5, -3};
    
    cout << "Unsorted Array:\n";
    printArray(sortArr, ARRAY_SIZE);
    
    CoolSort(sortArr, ARRAY_SIZE, H, SEQUENCE_SIZE);
    
    printArray(sortArr, ARRAY_SIZE);
    
    return 0;
}



void CoolSort(int arr[], int arrSize, int sequence[], int sequenceSize)
{
    
    for(int i = 0; i < sequenceSize; i++)
    {
        for(int j = 0; j < sequence[i]; j++){
            
            for(int k = j; k < arrSize; k += sequence[i]){
                
                int value = arr[k];
                int hole = k;
                
                while(hole > j && arr[hole - sequence[i]] > value)
                {
                    arr[hole] = arr[hole - sequence[i]];
                    hole = hole - sequence[i];
                }
                arr[hole] = value;
            }
            
        }
        
        // prints the array after each sort to show it is working correctly
        //cout << "Sort after Sequence " << sequence[i] << ":\n";
        //printArray(arr, arrSize);
    }
    
}


/*
 helper function to print the array
 */
void printArray(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ((i == size -1) ? "\n\n" : ", ");
    }
}