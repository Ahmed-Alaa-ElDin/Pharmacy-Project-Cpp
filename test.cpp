#include <iostream>
#include <string>
#include "pharmList/pharmList.cpp"

using namespace std;

int main()
{
    pharmList insurance("Insurance",5,2);
    insurance.assignPatient(1, 2);
    insurance.assignPatient(3, 43);
    insurance.assignPatient(6, 23);
    insurance.assignPatient(2, 7);
    insurance.dispense();
    insurance.dispense();
    insurance.dispense();
    insurance.status();

    return 0;
}