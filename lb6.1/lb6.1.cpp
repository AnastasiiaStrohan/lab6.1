#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;


void CreateArray(int* arr, const int size, const int Low, const int High, int i = 0) {
    if (i < size) {
        arr[i] = Low + rand() % (High - Low + 1);
        CreateArray(arr, size, Low, High, i + 1); 
    }
}
void PrintArray(int* arr, const int size, int i = 0) {
    if (i < size) {
        cout << setw(4) << arr[i];
        PrintArray(arr, size, i + 1); 
    }
}


int CountElements(int* arr, const int size, int i = 0) {
    if (i == size)
        return 0; 
    return ((arr[i] > 0 && arr[i] % 4 != 0) ? 1 : 0) + CountElements(arr, size, i + 1); 
}


int SumElements(int* arr, const int size, int i = 0) {
    if (i == size)
        return 0; 
    return ((arr[i] > 0 && arr[i] % 4 != 0) ? arr[i] : 0) + SumElements(arr, size, i + 1); 
}


void ReplaceWithZero(int* arr, const int size, int i = 0) {
    if (i < size) {
        if (arr[i] > 0 && arr[i] % 4 != 0)
            arr[i] = 0; 
        ReplaceWithZero(arr, size, i + 1); 
    }
}

int main() {
    srand((unsigned)time(NULL));

    const int n = 23; 
    int arr[n];
    int Low = -19, High = 25;

    
    CreateArray(arr, n, Low, High);

   
    cout << "original massiv\n";
    PrintArray(arr, n);
    cout << endl;

    
    int count = CountElements(arr, n);
    int sum = SumElements(arr, n);

    
    ReplaceWithZero(arr, n);

    
    cout << "\nnumber of elements " << count << endl;
    cout << "sum  of elements  " << sum << endl;

    
    cout << "\nresult\n";
    PrintArray(arr, n);
    cout << endl;

    return 0;
}
