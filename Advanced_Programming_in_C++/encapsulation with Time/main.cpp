#include <iostream>
using namespace std;

//Encapsulation with Time
class Time {
protected:
    int hour_protected;
    int minute_protected;
    int second_protected;
public:
    Time(int h = 00, int m = 00, int s = 00) {
        hour_protected = h;
        minute_protected = m;
        second_protected = s;
    }
    ~Time() {
        cout << "Object Time destroyed" << endl;
    }
    void setTime (int h = 00, int m = 00, int s = 00) {
        hour_protected = h;
        minute_protected = m;
        second_protected = s;
    }

    void incrementTime(int h = 0, int m = 0, int s = 0) {
        hour_protected += h;
        minute_protected += m;
        second_protected += s;
    }
    void getTime() {
        cout << hour_protected << ":" << minute_protected << ":" << second_protected << endl;
    }

};
int main () {
    Time time1(00,00,00);
    time1.getTime();
    time1.setTime(10,10,10);
    time1.getTime();
    time1.incrementTime(1,1,1);
    time1.getTime();

    return 0;
}

