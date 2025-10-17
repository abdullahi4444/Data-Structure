#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    struct employee {
        int id;
        float salary;
        int mobile;
    };

    struct employee e1, e2, e3;

    cout << "Enter ids, salary & mobile no. of 3 employees:\n";
    cin >> e1.id >> e1.salary >> e1.mobile;
    cin >> e2.id >> e2.salary >> e2.mobile;
    cin >> e3.id >> e3.salary >> e3.mobile;

    cout << "\nEntered Result:\n";
    cout << e1.id << " " << e1.salary << " " << e1.mobile << endl;
    cout << e2.id << " " << e2.salary << " " << e2.mobile << endl;
    cout << e3.id << " " << e3.salary << " " << e3.mobile << endl;

    getch();
    return 0;
}
