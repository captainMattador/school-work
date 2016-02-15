

/*--------------------------------------------------------------------
 Title: Lab 6 - Linear and Binary Search - Bozelka
 File: Driver for the lab
 Abstract: This lab explores a few different types of searches.
 The first search is a simple linear search, the next search is a 
 binary search done iteratively, and the 3rd search type is a
 binary search done recursively.
 Author: Matthew Bozelka
 ID: 002276039
 Date: 02/12/2016
 --------------------------------------------------------------------*/


#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int searchFor);
bool IterBinarySearch(int arr[], int size, int searchFor);
bool RecursiveBinarySearch(int arr[], int start, int end, int searchFor);
void printArray(int arr[], int size);


int main(int argc, const char * argv[]) {
    
    const int SEARCH_FOR = 200;
    
    bool foundInSearch;
    int searchArray[10] = {-5, 3, 6, 10, 47, 100, 101, 110, 173, 200};
    
    cout << "Part A: Linear Search\nPrint of array being searched.\n";
    printArray(searchArray, 10);
    cout << "Looking for " << SEARCH_FOR << ": ";
    foundInSearch = LinearSearch(searchArray, 10, SEARCH_FOR);
    (foundInSearch) ? printf("%d was found!\n", SEARCH_FOR) : printf("%d was not found :(\n", SEARCH_FOR);
    
    
    cout << "\n\nPart B: Iterative Binary Search\nPrint of array being searched.\n";
    printArray(searchArray, 10);
    cout << "Looking for " << SEARCH_FOR << ": ";
    foundInSearch = IterBinarySearch(searchArray, 10, SEARCH_FOR);
    (foundInSearch) ? printf("%d was found!\n", SEARCH_FOR) : printf("%d was not found :(\n", SEARCH_FOR);
    
    cout << "\n\nPart C: Recursive Binary Search\nPrint of array being searched.\n";
    printArray(searchArray, 10);
    cout << "Looking for " << SEARCH_FOR << ": ";
    foundInSearch = RecursiveBinarySearch(searchArray, 0, 10, SEARCH_FOR);
    (foundInSearch) ? printf("%d was found!\n", SEARCH_FOR) : printf("%d was not found :(\n", SEARCH_FOR);
    
    
    cout << endl;
    return 0;
}

bool RecursiveBinarySearch(int arr[], int start, int end, int searchFor)
{

    if(start > end)
        return false;

    int mid = start + (end - start) / 2;
    
    if(arr[mid] == searchFor)
        return true;
    else if(searchFor < arr[mid])
        return RecursiveBinarySearch(arr, start, mid - 1, searchFor);
    else
        return RecursiveBinarySearch(arr, mid + 1, end, searchFor);
    
}

bool IterBinarySearch(int arr[], int size, int searchFor)
{
    int start = 0, end = size - 1;
    
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] == searchFor)
            return true;
        else if(searchFor < arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    
    return false;
}

bool LinearSearch(int arr[], int size, int searchFor)
{
    
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == searchFor)
            return true;
    }
    
    return false;
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
