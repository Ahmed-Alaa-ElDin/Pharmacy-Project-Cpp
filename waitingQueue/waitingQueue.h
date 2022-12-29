class waitingQueue
{
private:
    class patient
    {
    public:
        int ID;
        int items;
        bool emergency;
        patient *next;
    };

    patient *front, *rear;
    int size;
    int lastID;
    int emergencyNo;

public:
    waitingQueue(int);                       // constructor of new patients' queue
    void entrance(int, bool);                // New Patient Entered the queue
    void entranceEmergency(int, bool);       // New urgent Patient Entered the queue
    void serve(int &, int &, bool &);        // Distribute The First Patient
    void firstPatient(int &, int &, bool &); // Get the data of the first Patient
    int queueSize();                         // Get the size of the queue
    bool queueIsEmpty();                     // Is the queue empty or not?
    int getLastID();                         // Get the ID of the last Patient added to the queue
    int getEmergencyNo();                    // Get the number of Urgent Patients
};