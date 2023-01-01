#include <string>

using namespace std;

class pharmList
{
private:
    class patient
    {
    public:
        int ID;
        int items;
    };

    string department;
    int size;
    int rate;

    patient **pharmacists;

public:
    pharmList(string, int = 10, int = 1);
    int getSize() const;
    string getDepartment() const;
    bool available() const;
    int availableNo() const;
    int oldestFree() const;
    int patientsBeingServed() const;
    void assignPatient(int, int);
    void dispense();
    void status();
};