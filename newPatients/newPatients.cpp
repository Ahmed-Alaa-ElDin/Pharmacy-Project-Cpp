#include "newPatients.h"
#include <iostream>

using namespace std;

// constructor of new patients' queue
newPatients::newPatients()
{
    front = rear = NULL;
    size = 0;
}

// New Patient Entered the queue
void newPatients::entrance(int t, int it, bool em)
{
    patient *newNode = new patient;

    newNode->type = t;
    newNode->items = it;
    newNode->emergency = em;
    newNode->next = NULL;

    if (queueIsEmpty())
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

// Distribute The First Patient
void newPatients::distribute(int &t, int &it, bool &em)
{
    if (!queueIsEmpty())
    {
        patient *deleteNode;
        deleteNode = front;

        t = front->type;
        it = front->items;
        em = front->emergency;

        if (size == 1)
        {
            front = rear = NULL;
            delete deleteNode;
        }
        else
        {
            front = front->next;
            delete deleteNode;
        }

        size--;
    }
}

// Get the data of the first Patient
void newPatients::firstPatient(int &t, int &it, bool &em)
{
    t = front->type;
    it = front->items;
    em = front->emergency;
}

// Get the size of the queue
int newPatients::queueSize()
{
    return size;
}

int newPatients::emergencyPatientsNo()
{
    int count = 0;
    patient *p = front;

    while (p)
    {
        if (p->emergency)
            count++;

        p = p->next;
    }

    return count;
}

// Is the queue empty or not?
bool newPatients::queueIsEmpty()
{
    return size == 0;
}

void newPatients::status()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "No. of patients in the queue is " << queueSize() << " ." << endl;
    cout << "No. of emergency patients is " << emergencyPatientsNo() << " ." << endl;
    cout << "No. of regular patients is " << queueSize() - emergencyPatientsNo() << " ." << endl;
    cout << "----------------------------------------------------------------" << endl;
}
