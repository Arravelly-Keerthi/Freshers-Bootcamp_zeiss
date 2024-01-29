#include <iostream>
#include <string>
using namespace std;

class Door {
public:
    void open() {
        cout << "Door opened" << endl;
    }

    void close() {
        cout << "Door closed" << endl;
    }
};

class Buzzer {
public:
    void makeNoise() {
        cout << "Buzzer making noise" << endl;
    }
};

class SMSManager {
public:
    void sendNotificationMessage() {
        cout << "Sending notification message" << endl;
    }
};

class VisualizationManager {
public:
    void turnVideoOn() {
        cout << "Turning video on" << endl;
    }

    void turnVideoOff() {
        cout << "Turning video off" << endl;
    }
};

class SmartDoor : public Door {
private:
    Buzzer buzzer;
    SMSManager smsManager;
    VisualizationManager visualizationManager;

public:
    void activateBuzzer() {
        buzzer.makeNoise();
    }

    void sendNotification() {
        smsManager.sendNotificationMessage();
    }

    void turnVideoOn() {
        visualizationManager.turnVideoOn();
    }

    void turnVideoOff() {
        visualizationManager.turnVideoOff();
    }
};

class SmartDoorBuilder {
private:
    SmartDoor* smartDoor;

public:
    SmartDoorBuilder() : smartDoor(new SmartDoor()) {
    }

    SmartDoorBuilder* addBuzzer() {
        cout << " Buzzer to SmartDoor " << endl;
        return this;
    }

    SmartDoorBuilder* addSMSManager() {
        cout << "Adding SMS Manager to SmartDoor" << endl;
        return this;
    }

    SmartDoorBuilder* addVisualizationManager() {
        cout << "Adding Visualization Manager to SmartDoor" << endl;
        return this;
    }

    SmartDoor* build() {
        return smartDoor;
    }
};

int main() {
    SmartDoor* mySmartDoor = (new SmartDoorBuilder())->build();
    mySmartDoor->open();  
    mySmartDoor->close(); 
    mySmartDoor->activateBuzzer(); 

    SmartDoor* mySmartDoor1 = (new SmartDoorBuilder())->addSMSManager()->build();
    mySmartDoor1->open(); 
    mySmartDoor1->close(); 
    mySmartDoor1->sendNotification();  

    SmartDoor* mySmartDoor2 = (new SmartDoorBuilder())->addSMSManager()->addVisualizationManager()->build();
    mySmartDoor2->open(); 
    mySmartDoor2->close(); 
    mySmartDoor2->turnVideoOn(); 
    mySmartDoor2->turnVideoOff(); 

    delete mySmartDoor;
    delete mySmartDoor1;
    delete mySmartDoor2;

    return 0;
}
