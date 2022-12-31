#include <iostream>
#include <string>
#include "pharmList/pharmList.cpp"

using namespace std;

int main()
{
    pharmList insurance("Insurance",5,2);
    pharmList cash("Cash",2,1);
    insurance.assignPatient(3, 43);
    insurance.assignPatient(6, 23);
    insurance.assignPatient(6, 23);
    insurance.assignPatient(6, 23);
    insurance.assignPatient(2, 7);
    insurance.dispense();
    insurance.dispense();
    insurance.dispense();
    insurance.status();
    cash.assignPatient(2, 7);
    cash.dispense();
    cash.status();

    return 0;
}