#include <iostream>
#include <math.h>
#include <typeinfo>

using namespace std;

double getUserInput (int mode) {
    double n;

    cout << "Enter number:";
    cin >> n;

    switch (mode) {
        case 1:
            if(n <= 1) {
                throw exception("Non-relevant number (negative, zero or one)!");
            }
            break;
        case 2:
            if(n <= 0) {
                throw exception("Non-relevant number (negative or zero)!");
            }
            break;
    }

    return n;
}

double getNumber(double number, int mode) {
    number = 0.0;
    while (number <= 0) {
        try {
            number = getUserInput(mode);
        } catch (const exception &ex) {
            cout << ex.what() << endl;
        } catch (...) {
            cout << "ERROR" << endl;
        }
    }
    return number;
}

void findPrimeNumbers(int limit) {
    int i;
    for (int n = 1; n <= limit; n++) {
        i = 2;
        while (i <= n) {
            if (n % i == 0) {
                break;
            }
            i++;
        }

        if (n == i) {
            cout << " " << i;
        }
    }
    cout << endl;
}

int main() {
    int primeMode = 1;
    int otherMode = 2;
    double n = 0.0;

    cout << "____Square Root of Number____" << endl;
    n = getNumber(n,otherMode);
    cout << sqrt(n) << endl;

    cout << "____Logarithm base 2 of Number____" << endl;
    n = getNumber(n,otherMode);
    cout << log2(n) << endl;

    cout << "____Prime Numbers____" << endl;
    n = getNumber(n,primeMode);
    findPrimeNumbers(n);

    return 0;
}