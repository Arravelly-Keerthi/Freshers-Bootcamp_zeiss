#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IObserver {
public:
    virtual void notify() = 0;
    virtual ~IObserver() {} // Adding a virtual destructor for the base class
};

class Buzzer : public IObserver {
public:
    void notify() override {
        activateBuzzer();
    }

private:
    void activateBuzzer() {
        cout << "Buzzer activated." << endl;
    }
};

class SMSNotifier : public IObserver {
public:
    void notify() override {
        sendSMS();
    }

private:
    void sendSMS() {
        cout << "SMS notification sent." << endl;
    }
};

class VisualizationManager : public IObserver {
public:
    void notify() override {
        displayVisualization();
    }

private:
    void displayVisualization() {
        cout << "Visualization displayed." << endl;
    }
};

class SmartDoor {
    int maxObservers;
    int numObservers;
    IObserver** observers;

public:
    SmartDoor(int max) : maxObservers(max), numObservers(0) {
        observers = new IObserver*[maxObservers];
    }

    ~SmartDoor() {
        for (int i = 0; i < numObservers; ++i) {
            delete observers[i];
        }
        delete[] observers;
    }

    void openDoor() {
        cout << "Door is opened." << endl;
        notifyObservers();
    }

    void CloseDoor() {
        cout << "Door is closed." << endl;
    }

    void addObserver(IObserver* observer) {
        if (numObservers < maxObservers) {
            observers[numObservers++] = observer;
        } else {
            cout << "Max observers reached." << std::endl;
        }
    }

    void removeObserver(IObserver* observer) {
        for (int i = 0; i < numObservers; ++i) {
            if (observers[i] == observer) {
                delete observers[i];
                for (int j = i; j < numObservers - 1; ++j) {
                    observers[j] = observers[j + 1];
                }
                --numObservers;
                break;
            }
        }
    }

    void notifyObservers() {
        for (int i = 0; i < numObservers; ++i) {
            observers[i]->notify();
        }
    }
};

int main() {
    int maxObservers;
    cout << "Enter the maximum number of observers: ";
    cin >> maxObservers;

    SmartDoor smartDoor(maxObservers);

    smartDoor.openDoor();

    Buzzer* buzzer = new Buzzer();
    smartDoor.addObserver(buzzer);

    SMSNotifier* s = new SMSNotifier();
    smartDoor.addObserver(s);

    smartDoor.openDoor();
    smartDoor.removeObserver(buzzer);
    smartDoor.removeObserver(s);

    return 0;
}
