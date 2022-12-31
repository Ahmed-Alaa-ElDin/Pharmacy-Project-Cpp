#include "waitingQueue.h"
#include <iostream>

using namespace std;

// constructor of new patients' queue
waitingQueue::waitingQueue(int l_id)
{
    front = rear = NULL;
    size = 0;
    lastID = l_id;
    emergencyNo = 0;
}

// New Patient Entered the queue
void waitingQueue::entrance(int it)
{
    patient *newNode = new patient;
    newNode->ID = lastID;
    newNode->items = it;
    newNode->next = NULL;

    if (queueIsEmpty())
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
    lastID++;
}

// New urgent Patient Entered the queue
void waitingQueue::entranceEmergency(int it)
{
    patient *newNode = new patient;
    newNode->ID = lastID;
    newNode->items = it;
    newNode->next = NULL;

    if (queueIsEmpty())
        front = rear = newNode;
    else if (!getEmergencyNo())
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        patient *temp = front;
        for (int i = 1; i < emergencyNo; i++)
            temp = temp->next;
        if (temp != rear)
            newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Distribute The First Patient
void waitingQueue::serve(int &id, int &it)
{
    if (!queueIsEmpty())
    {
        cout << size << endl;
        patient *deleteNode;
        deleteNode = front;

        id = front->ID;
        it = front->items;

        if (size == 1)
        {
            front = rear = NULL;
            delete (deleteNode);
        }
        else
        {
            front = front->next;
            delete (deleteNode);
        }

        size--;
    }
}

// Get the data of the first Patient
void waitingQueue::firstPatient(int &id, int &it)
{
    id = front->ID;
    it = front->items;
}

// Get the size of the queue
int waitingQueue::queueSize()
{
    return size;
}

// Is the queue empty or not?
bool waitingQueue::queueIsEmpty()
{
    return size == 0;
}

// Get the ID of the last Patient added to the queue
int waitingQueue::getLastID()
{
    return lastID;
}

// Get the ID of the last Patient added to the queue
int waitingQueue::getEmergencyNo()
{
    return emergencyNo;
}
