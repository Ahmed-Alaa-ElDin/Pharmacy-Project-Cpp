#include "pharmList.h"
#include <iostream>
#include <string>

using namespace std;

pharmList::pharmList(string t, int s, int r)
{
    size = s;
    rate = r;
    department = t;

    pharmacists = new patient *[size];

    for (int i = 0; i < size; i++)
    {
        patient *newPatient = new patient;
        newPatient->ID = 0;
        newPatient->items = 0;

        pharmacists[i] = newPatient;
    }
}

int pharmList::getSize() const
{
    return size;
}

string pharmList::getDepartment() const
{
    return department;
}

bool pharmList::available() const
{
    for (int i = 0; i < size; i++)
    {
        if (pharmacists[i]->items <= 0)
            return true;
    }
    return false;
}

int pharmList::oldestFree() const
{
    if (available())
    {
        int min_items = pharmacists[0]->items;
        int min_index = 0;

        for (int i = 0; i < size; i++)
        {
            if (pharmacists[i]->items < min_items)
            {
                min_items = pharmacists[i]->items;
                min_index = i;
            }
        }

        return min_index;
    }

    return -1;
}

int pharmList::patientsBeingServed() const
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (pharmacists[i]->items > 0)
            counter++;
    }

    return counter;
}

void pharmList::assignPatient(int i, int it)
{
    int oldFreeIndex = oldestFree();

    if (oldFreeIndex != -1)
    {
        pharmacists[oldFreeIndex]->items = it;
        pharmacists[oldFreeIndex]->ID = i;
    }
}

void pharmList::dispense()
{
    for (int i = 0; i < size; i++)
    {
        pharmacists[i]->items -= rate;

        if (pharmacists[i]->items == 0)
            pharmacists[i]->ID = 0;
    }
}

void pharmList::status()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "Status of " << department << " Department" << endl;
    cout << "No. of Pharmacists => " << size << endl;
    cout << "No. of Patients being served => " << patientsBeingServed() << endl;
    for (int i = 0; i < size; i++)
    {
        if (pharmacists[i]->items > 1)
            cout << "Pharmacist #" << i + 1 << " is serving patient #" << pharmacists[i]->ID << " and " << pharmacists[i]->items << " items are remaining" << endl;
        else if (pharmacists[i]->items > 0)
            cout << "Pharmacist #" << i + 1 << " is serving patient #" << pharmacists[i]->ID << " and one item is remaining" << endl;
        else
            cout << "Pharmacist #" << i + 1 << " is free" << endl;
    }
    if (available())
    {
        cout << "It's the turn of pharmacist #" << oldestFree() + 1 << "." << endl;
    }

    cout << "----------------------------------------------------------------" << endl;
}
