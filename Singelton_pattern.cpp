#include <iostream>
#include <string>

using namespace std;  
class ICommunicationManager {
public:
    virtual void shareContent(string imageLink) = 0;
};

class ImageGallery {
private:
ImageGallery() {}
    string images[5] = { "one.jpg", "two.jpg", "three.jpg", "four.jpg", "five.jpg" };
public:
static ImageGallery* getInstance() {
        static ImageGallery instance; 
        return &instance;
    }
    void share(int index, ICommunicationManager* comManager) {
        comManager->shareContent(images[index]);
    }
};

class BluetoothManager : public ICommunicationManager {
private:
    BluetoothManager() {} 
public:
    static BluetoothManager* getInstance() {
        static BluetoothManager instance; 
        return &instance;
    }

    void searchDevices() {}
    void pairDevice() {}
    void sendContent() {}
    void turnOn() {}
    void turnOff() {}
    void shareContent(string imageLink) override {
    
    }
};

class WhatsUpManager : public ICommunicationManager {
private:
    WhatsUpManager() {} 
public:
    static WhatsUpManager* getInstance() {
        static WhatsUpManager instance;
        return &instance;
    }

    void turnOn() {}
    void turnOff() {}
    void shareContent(string imageLink) override {
    
    }
    void joinGroup() {}
    void addMember() {}
    void createGroup() {}
};

class MailManager : public ICommunicationManager {
private:
    MailManager() {} 
public:
    static MailManager* getInstance() {
        static MailManager instance;
        return &instance;
    }

    void pullNewMails() {}
    void senMails() {}
    void composeEmail() {}
    void addAttachment() {}
    void shareContent(string imageLink) override {
        
    }
};

int main() {
    MailManager* _mailManager = MailManager::getInstance();
	BluetoothManager* _bluetoothManager = BluetoothManager::getInstance();
	WhatsUpManager* _whatsUpManager = WhatsUpManager::getInstance();
	
	ImageGallery* imageMgmt = ImageGallery::getInstance();
	imageMgmt->share(0,_mailManager);
	imageMgmt->share(0,_bluetoothManager);
	imageMgmt->share(0,_whatsUpManager);
}
