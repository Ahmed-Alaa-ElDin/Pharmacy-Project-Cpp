class newPatients
{
private:
    class patient
    {
    public:
        int items;
        int type; // 0 => cash , 1 => insurance
        bool emergency;
        patient *next;
    };

    patient *front, *rear;
    int size;

public:
    newPatients();                           // constructor of new patients' queue
    void entrance(int, int, bool);           // New Patient Entered the queue
    void distribute(int &, int &, bool &);   // Distribute The First Patient
    void firstPatient(int &, int &, bool &); // Get the data of the first Patient
    int queueSize();                         // Get the size of the queue
    int emergencyPatientsNo();               // Get the number of emergency patients
    bool queueIsEmpty();                     // Is the queue empty or not?
    void status();                           // Prints the status of the new Patients queue
};