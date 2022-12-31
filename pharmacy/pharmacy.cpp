#include <string>
#include "pharmacy.h"
#include "../pharmList/pharmList.cpp"
#include "../waitingQueue/waitingQueue.cpp"
#include "../newPatients/newPatients.cpp"

using namespace std;

pharmacy::pharmacy()
{
    int cashNo, cashRate, insuranceNo, insuranceRate;
    int newPatientsNo;
    int items, type;
    bool emergency;

    cout << "Kindly enter the number of pharmacists in 'cash department' ";
    cin >> cashNo;
    cout << "How many items will be dispensed per each round in 'cash department'? ";
    cin >> cashRate;

    cout << "Kindly enter the number of pharmacists in 'insurance department' ";
    cin >> insuranceNo;
    cout << "How many items will be dispensed per each round in 'insurance department'? ";
    cin >> insuranceRate;

    newPatients newPatientsQueue;
    waitingQueue cashQueue(1000), insuranceQueue(2000);
    pharmList cash("Cash", (int)cashNo, (int)cashRate), insurance("Insurance", (int)insuranceNo, (int)insuranceRate);

    while (true)
    {
        cout << "How many patients entered the pharmacy? ";
        cin >> newPatientsNo;

        for (int i = 0; i < newPatientsNo; i++)
        {
            cout << "How many items will be dispensed for the patient #" << i + 1 << " ? ";
            cin >> items;
            cout << "Cash (0) or Insurance (1) ? ";
            cin >> type;
            cout << "Regular (0) or Emergency (1) ? ";
            cin >> emergency;

            newPatientsQueue.entrance(type, items, emergency);
        }

        newPatientsQueue.status();

        for (int i = 0; i < newPatientsQueue.queueSize(); i++)
        {
            newPatientsQueue.distribute(type, items, emergency);

            if (type == 0) {
                if (emergency == 0) {
                    cashQueue.entrance(items);
                } else {
                    cashQueue.entranceEmergency(items);
                }
            } else {
                if (emergency == 0) {
                    insuranceQueue.entrance(items);
                } else {
                    insuranceQueue.entranceEmergency(items);
                }
            }
        }
        


            // if (type == 0)
            // {
            // }
            // else if (type == 1)
            // {
            // }
            // else
            // {
            //     cout << "Invalid type" << endl;
            // }

        break;
    }
}
