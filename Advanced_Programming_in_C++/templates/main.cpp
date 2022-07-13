#include <iostream>
#include <random>
#include <array>
#include <typeinfo>

using namespace std;

//Task 1
template <class T>
class ArrayClass {
private:
    T* arr;
    T min;
    T max;
    int s;

public:
    ArrayClass(int size, T min_rand_num, T max_rand_num) {
        s = size;
        arr = new T [s];
        min = min_rand_num;
        max = max_rand_num;

    }
    ~ArrayClass() {
        delete[] this->arr;
    }

    void printArray () {
        for (int i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    T random() {
        random_device rd;
        mt19937 gen(rd());
        if (typeid(arr).name() == "float" || "double" || "long double") {
            uniform_real_distribution<> distrib(min, max);
            return distrib(gen);
        } else {
            uniform_int_distribution<> distrib(min, max);
            return distrib(gen);
        }
    }
    void fillArrayWithZeros () {
        for (int i = 0; i < s; i++) {
            arr[i] = 0;
        }
    }
    void fillArrayWithNumbers () {
        for (int i = 0; i < s; i++) {
            arr[i] = random();
        }
    }
    void bubbleSort () {
        int length = s;

        while(length >= 1) {
            int new_length = 0;
            for (int i = 1; i <= length - 1; i++) {
                if (arr[i - 1] > arr[i]) {
                    T temp = arr[i - 1];
                    arr[i - 1] = arr[i];
                    arr[i] = temp;

                    new_length = i;
                }
            }
            length = new_length;
        }
    }
};

int main() {
    int size = 10;
    do {
        cout << "Enter size of list: ";
        cin >> size;
        cout << endl;
    } while (size < 1);

    cout << "_____________1. Int array_____________" << endl;
    ArrayClass<int> int_arr(size, 0, 99);
    cout << "Initial Array:" << endl;
    int_arr.fillArrayWithNumbers();
    int_arr.printArray();
    cout << "Sorted with Bubble sort: " << endl;
    int_arr.bubbleSort();
    int_arr.printArray();

    cout << "_____________2. Double array_____________" << endl;
    ArrayClass<double> double_arr(10, 0.0, 10.0);
    cout << "Initial Array:" << endl;
    double_arr.fillArrayWithNumbers();
    double_arr.printArray();
    cout << "Sorted with Bubble sort:" << endl;
    double_arr.bubbleSort();
    double_arr.printArray();

    return 0;


}

//Task 2
/*template <class T, class D>
class TwoDataMembers {
private:
    T a;
    D b;
public:
    TwoDataMembers() {
        a = 0;
        b = 0;
    }
    //~TwoDataMembers();

    void getMembs();
    void setMembs(T a, D b);
    void displayMembs();
};

template <class T, class D>
void TwoDataMembers<T, D>::setMembs(T a, D b) {
    this->a = a;
    this->b = b;
}

template <class T, class D>
void TwoDataMembers<T, D>::getMembs() {
    T m1;
    D m2;

    cout << "Enter the first member: ";
    cin >> m1;

    cout << "Enter the second member: ";
    cin >> m2;

    setMembs(m1, m2);
}

template <class T, class D>
void TwoDataMembers<T, D>::displayMembs() {
    cout << "member1: " << this->a << endl;
    cout << "member2: " << this->b << endl;
}

int main() {
    TwoDataMembers<int, char> data_type;
    data_type.getMembs();
    data_type.displayMembs();

}*/

//Task 3
/*template <class T>
class Stack {
private:
    T *arr;
    int size;
public:
    Stack(int size) {
        this->size = size;
        arr = new T [size];
    }
    ~Stack() {
        delete [] arr;
    }

    T random() {
        random_device rd;
        mt19937 gen(rd());
        if (typeid(arr).name() == "float" || "double" || "long double") {
            uniform_real_distribution<> distrib(0.0, 100.0);
            return distrib(gen);
        } else {
            uniform_int_distribution<> distrib(0, 100);
            return distrib(gen);
        }
    }
    void fillArrayWithNumbers () {
        for (int i = 0; i < size; i++) {
            arr[i] = random();
        }
    }
    void printArray () {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void pushBack(T element) {
        T *new_arr = new T [size + 1];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }
        new_arr[size] = element;
        size++;

        delete [] arr;
        arr = new_arr;
    }

    void popBack() {
        size--;
        T *new_arr = new T [size];
        for (int i = 0; i < size; i++) {
            new_arr[i] = arr[i];
        }

        delete [] arr;
        arr = new_arr;
    }

    T maxElement () {
        T max = arr[0];
        for (int i = 1; i < size; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }

    T sumOfArray() {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    int sizeOfArray() {
        return size;
    }
};

int main() {
    int size;
    do {
        cout << "Size of initial array (not less than 1): ";
        cin >> size;
    } while (size < 1);

    //Stack<int> arr(size);
    Stack<double> arr(size);
    //Stack<char> arr(size);

    cout << "--------Initial Array--------" << endl;
    arr.fillArrayWithNumbers();
    arr.printArray();
    cout << "elements in array: " << arr.sizeOfArray() << endl;
    cout << "max: " << arr.maxElement() << endl;
    cout << "sum: " << arr.sumOfArray() << endl;

    cout << "--------PushBack--------" << endl;
    arr.pushBack(arr.random());
    arr.printArray();
    cout << "elements in array: " << arr.sizeOfArray() << endl;
    cout << "max: " << arr.maxElement() << endl;
    cout << "sum: " << arr.sumOfArray() << endl;

    cout << "--------PopBack--------" << endl;
    arr.popBack();
    arr.printArray();
    cout << "elements in array: " << arr.sizeOfArray() << endl;
    cout << "max: " << arr.maxElement() << endl;
    cout << "sum: " << arr.sumOfArray() << endl;

    return 0;
}*/
