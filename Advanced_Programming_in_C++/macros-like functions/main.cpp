//Quick sort and DEC to BIN with Function-like Macros (excluding main body of quick sort)


#include <iostream>
#include <random>
#include <typeinfo>

using namespace std;

#define SIZE 10

#define SWAP(a,b) int tmp = a; a = b; b = tmp;
#define PARTITION(arr,first_num,last_num,pi) do { \
   int pivot = arr[last_num];                       \
   int i = first_num - 1;                           \
   for (int j = first_num; j < last_num; j++) {     \
      if (arr[j] <= pivot) {                      \
         i++;                                        \
         SWAP(arr[i], arr[j]);                     \
      }                                           \
   }                                                \
   SWAP(arr[i + 1], arr[last_num]);               \
                                                 \
   pi = i + 1;                                  \
} while(0)

#define RANDOM(number) do { \
   random_device rd;           \
   mt19937 gen(rd());          \
   uniform_real_distribution<> distrib(0, 99); \
   number = distrib(gen);                        \
} while(0)

#define FILLARRWITHRANDNUM(arr) do { \
   for (int i = 0; i < SIZE; i++) {           \
      int num;                            \
      RANDOM(num);                        \
                                    \
      arr[i] = num;                       \
   }                                   \
} while(0)

#define PRINTARR(arr) do { \
     for (int i = 0; i < SIZE; i++) {    \
     cout << arr[i] << " ";              \
     }                                   \
     cout << endl;                       \
} while(0)

#define DECTOBIN(num) do { \
   int a[10];                   \
   int i;                       \
   int tmp = num;               \
                                \
   for(i = 0; tmp > 0; i++) {   \
      a[i] = tmp % 2;           \
      tmp /= 2;                 \
   }                            \
   for(i = i - 1 ;i >= 0 ; i--) { \
      cout << a[i];             \
   }                            \
} while(0)

#define PRINTBINARR(arr) do { \
   for(int sm = 0; sm < SIZE; sm++) { \
      DECTOBIN(arr[sm]);            \
      cout << " ";                 \
   }\
} while(0)

void quickSort(int* arr, int first_number, int last_number) {
    if (first_number < last_number) {
        int pi;
        PARTITION(arr,first_number,last_number,pi);

        quickSort(arr, first_number, pi - 1);

        quickSort(arr, pi + 1, last_number);
    }
}

int main() {
    int *arr = new int [SIZE];

    //Initial Array
    FILLARRWITHRANDNUM(arr);
    PRINTARR(arr);

    //Quick sort - not possible to make recursion with Macros-like functions
    quickSort(arr,0,SIZE-1);
    PRINTARR(arr);

    //Convert number to binary
    PRINTBINARR(arr);

    delete [] arr;
    return 0;
}