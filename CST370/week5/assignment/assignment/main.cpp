
#include <iostream>
using namespace std;


void SelectionSort(int arr[], int size); // part a of assignment
void SelectionSortPartB(int arr[], int arrSize, int sortSection); // part b of assignment
double median(int arr[], int size);
void printArray(int arr[], int size);


int main(int argc, const char * argv[]) {
    
    int selectionSortArrPartA[10] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
    int selectionSortArrPartB[10] = {4, 6, 8, 15, 20, 22, 10, 3, 9, 2};
    int selectionSortArrPartC[6] = {4, 6, 8, 15, 20, 22};
    int userInput;
    double getMedian;
    
    
    /******************************************
     Part A Driver
     *****************************************/
    cout << "Selection sort Part A unsorted\n";
    printArray(selectionSortArrPartA, 10);
    
    SelectionSort(selectionSortArrPartA, 10);
    
    cout << "Selection sort Part A sorted\n";
    printArray(selectionSortArrPartA, 10);
    
    
    /******************************************
     Part B Driver
     *****************************************/
    do{
        cout << "Enter an integer >= 0: ";
        cin >> userInput;
        cin.clear();
        cin.ignore(10000, '\n');
        
        if(userInput <= 0)
            cout << "\nBad Input (try again)\n";
    }while(userInput <= 0);
    
    cout << "Selection sort Part B unsorted\n";
    printArray(selectionSortArrPartB, 10);
    
    SelectionSortPartB(selectionSortArrPartB, 10, userInput);
    
    cout << "Selection sort Part B sorted\n";
    printArray(selectionSortArrPartB, userInput);
    
    
    /******************************************
     Part C Driver
     *****************************************/
    getMedian = median(selectionSortArrPartC, 6);
    
    cout << "Part C array unsorted: \n";
    cout << "Median for part C array is: \n";
    cout << getMedian << endl << endl;
    
    
    return 0;
}


/*
    PART A selection sort
*/
void SelectionSort(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int swapIndex = i;
        
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[swapIndex])
                swapIndex = j;
        }
        
        if(swapIndex != i)
        {
            int temp = arr[swapIndex];
            arr[swapIndex] = arr[i];
            arr[i] = temp;
        }
    }
}




/*
    PART B selection sort
 */
void SelectionSortPartB(int arr[], int arrSize, int sortSection)
{
    
    if(sortSection > arrSize)
        sortSection = arrSize;

    
    for(int i = 0; i < sortSection; i++)
    {
        int swapIndex = i;
        
        for(int j = i + 1; j < arrSize; j++)
        {
            if(arr[j] < arr[swapIndex])
                swapIndex = j;
        }
        
        if(swapIndex != i)
        {
            int temp = arr[swapIndex];
            arr[swapIndex] = arr[i];
            arr[i] = temp;
        }
    }
}


/*
  returns the median of an array
  sorts the array in half first
*/
double median(int arr[], int size)
{
    
    int halved = size/2;
    
    // if even
    if(size % 2 == 0)
    {
        SelectionSortPartB(arr, size, halved + 1);
        return (double) (arr[halved] + arr[halved - 1])/2;
    }
    
    SelectionSortPartB(arr, size, halved);
    return (double) arr[halved];
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
