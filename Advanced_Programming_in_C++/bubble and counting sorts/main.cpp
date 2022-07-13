#include <iostream>
#include <random>
#include <array>

#define EMPTY 99

using namespace std;

class ArrayClass {
public:
    void static printArray (int arr[], const int size) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == EMPTY) {
                return;
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int static random() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distrib(0, 9);

        return distrib(gen);
    }
    void static fillArrayWithNumbers (int arr[], const int size) {
        for (int i = 0; i < size; i++) {
            arr[i] = random();
        }
    }
    void static fillArrayWithZeros (int arr[], const int size) {
        for (int i = 0; i < size; i++) {
            arr[i] = 0;
        }
    }
    void static copyOneArrayIntoAnother (int from[], int to[], int const size) {
        for (int i = 0; i < size; i++) {
            to[i] = from[i];
        }
    }
};

class Sort {
public:
    void bubbleSort (int arr[], int const size) {
        int length = size;
        bool isStop = false;

        //If array does not have any Number
        if (arr[0] == EMPTY) return;

        while(length >= 1) {
            int new_length = 0;
            for (int i = 1; i <= length - 1; i++) {
                if (arr[i - 1] > arr[i]) {
                    int temp = arr[i - 1];
                    arr[i - 1] = arr[i];
                    arr[i] = temp;

                    new_length = i;
                }

                if (arr[i] == EMPTY) {
                    isStop = true;
                    return;
                }
            }
            length = new_length;

            if (isStop) return;
        }
    }

    void countingSort (int arr[], int const size) {
        ArrayClass arrayClass;
        int k = 10;
        int *occur = new int[k];
        int *output = new int[size];

        arrayClass.fillArrayWithZeros(occur, k);
        arrayClass.fillArrayWithZeros(output, size);

        //Find occurrences of arr[] nums and store in occur[]
        for (int i = 0, j; i < size; i++) {
            j = arr[i];
            occur[j] += 1;
        }

        //Adding previous counts
        for (int i = 1; i < k; i++) {
            occur[i] += occur[i - 1];
        }

        //Allocate numbers in proper places
        for (int i = size - 1, j; i > 0; i--) {
            j = arr[i];
            occur[j] -=1;
            output[occur[j]] = arr[i];
        }

        arrayClass.copyOneArrayIntoAnother(output, arr, size);

        delete [] occur;
        delete [] output;
    }
};

int main() {
    ArrayClass arrayClass;
    Sort sort;
    int size = 0;
    cout << "Enter array size: ";
    cin >> size;

    int *arr = new int[size];

    arrayClass.fillArrayWithNumbers(arr, size);
    cout << "Initial Array:" << endl;
    //arrayClass.printArray(arr, size);

    int *arr_copy1 = new int[size];
    int *arr_copy2 = new int[size];
    arrayClass.copyOneArrayIntoAnother(arr, arr_copy1, size);
    arrayClass.copyOneArrayIntoAnother(arr, arr_copy2, size);

    cout << "Bubble Sort:" << endl;
    sort.bubbleSort(arr_copy1, size);
    //arrayClass.printArray(arr_copy1, size);

    cout << "Counting Sort:" << endl;
    sort.countingSort(arr_copy2, size);
    //arrayClass.printArray(arr_copy2, size);

    //Clean dynamic memory
    delete [] arr;
    delete [] arr_copy1;
    delete [] arr_copy2;

    return 0;
}
