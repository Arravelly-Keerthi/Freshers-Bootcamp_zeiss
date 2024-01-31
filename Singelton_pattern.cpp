

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
------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

class ICommunicationManager {
public:
    virtual void shareContent(string imageLink) = 0;
};

class ImageGallery {
private:
    static ImageGallery* instance;
    ImageGallery() {} 
    ImageGallery(const ImageGallery&);
    ImageGallery& operator=(const ImageGallery&);

public:
    static ImageGallery* getInstance() {
        if (!instance) {
            instance = new ImageGallery();
        }
        return instance;
    }

    string images[5] = { "one.jpg","two.jpg","three.jpg","four.jpg","five.jpg" };

    void share(int index, ICommunicationManager* comManager) {
        comManager->shareContent(images[index]);
    }
};

ImageGallery* ImageGallery::instance = nullptr;

class BluetoothManager : public ICommunicationManager {
private:
    static BluetoothManager* instance;
    BluetoothManager() {} 
    BluetoothManager(const BluetoothManager&);
    BluetoothManager& operator=(const BluetoothManager&);

public:
    static BluetoothManager* getInstance() {
        if (!instance) {
            instance = new BluetoothManager();
        }
        return instance;
    }

    void shareContent(string imageLink) override {}
};

BluetoothManager* BluetoothManager::instance = nullptr;

class WhatsUpManager : public ICommunicationManager {
private:
    static WhatsUpManager* instance;
    WhatsUpManager() {} 
    WhatsUpManager(const WhatsUpManager&);
    WhatsUpManager& operator=(const WhatsUpManager&);

public:
    static WhatsUpManager* getInstance() {
        if (!instance) {
            instance = new WhatsUpManager();
        }
        return instance;
    }

    void shareContent(string imageLink) override {}
};

WhatsUpManager* WhatsUpManager::instance = nullptr;

class MailManager : public ICommunicationManager {
private:
    static MailManager* instance;
    MailManager() {}
    MailManager(const MailManager&);
    MailManager& operator=(const MailManager&);

public:
    static MailManager* getInstance() {
        if (!instance) {
            instance = new MailManager();
        }
        return instance;
    }

    void shareContent(string imageLink) override {}
};

MailManager* MailManager::instance = nullptr;

int main() {
    MailManager* mailManager = MailManager::getInstance();
    BluetoothManager* bluetoothManager = BluetoothManager::getInstance();
    WhatsUpManager* whatsUpManager = WhatsUpManager::getInstance();

    ImageGallery* imageMgmt = ImageGallery::getInstance();
    imageMgmt->share(0, mailManager);
    imageMgmt->share(0, bluetoothManager);
    imageMgmt->share(0, whatsUpManager);
    
    delete mailManager;
    delete bluetoothManager;
    delete whatsUpManager;
    delete imageMgmt;

    return 0;
}
