#include <iostream>
using namespace std;

class KomponenRobotik {
public:
    virtual void jalankanTugas() = 0;   

    virtual ~KomponenRobotik() {}       
};

class PerangkatKeras : public KomponenRobotik {
protected:
    const char* nama;
    float konsumsiDaya;   

public:
    PerangkatKeras(const char* n, float daya) : nama(n), konsumsiDaya(daya) {}

    void nyalakan() {
        cout << "PerangkatKeras " << nama << ": Nyala. Konsumsi daya: " << konsumsiDaya << " A" << endl;
    }
};

class Mikrokontroler : public PerangkatKeras {
private:
    int pinPWM;   

public:
    Mikrokontroler(const char* n, float daya, int pin) : PerangkatKeras(n, daya), pinPWM(pin) {}

    void jalankanTugas() override {
        cout << "Mikrokontroler " << nama << " memproses logika program pada pin PWM: " << pinPWM << endl;
    }
};

class Aktuator : public PerangkatKeras {
private:
    int sudut;        
    int sudutMaks;

public:

    Aktuator(const char* n, float daya, int sMaks) : PerangkatKeras(n, daya) {
        sudut = 0;
        sudutMaks = sMaks;
    }
    
    void tambahSudut(int nilai) {
        if (sudut + nilai <= sudutMaks) {
            sudut += nilai;
        } else {
            sudut = sudutMaks;
        }
        cout << "Sudut sekarang: " << sudut << " derajat" << endl;
    }

    void tampilkanInfo() {
        cout << "Aktuator " << nama << ", sudut maks " << sudutMaks << " derajat" << endl;
    }

    virtual void gerakkan() {
        cout << "Aktuator " << nama << " bergerak pada umumnya." << endl;
    }

    void jalankanTugas() override {
        gerakkan();
    }
};

class MotorRobstride : public Aktuator {
public:
    MotorRobstride(const char* n, float daya, int sMaks) : Aktuator(n, daya, sMaks) {}

    void gerakkan() override {
        cout << "WUUUNGG Motor " << nama << " berputar cepat dan secara presisi." << endl;
    }
};

class Hidrolik : public Aktuator {
public:
    Hidrolik(const char* n, float daya, int sMaks) : Aktuator(n, daya, sMaks) {}

    void gerakkan() override {
        cout << "NNGGG SSSHHH.. " << nama << " mendorong lengan dengan kekuatan." << endl;
    }
};

int main() {

    MotorRobstride motorLengan("Robstride 06", 1.5, 180);
    motorLengan.tampilkanInfo();
    motorLengan.nyalakan();         
    motorLengan.tambahSudut(200);   

    KomponenRobotik* daftarKomponen[3];
    daftarKomponen[0] = new Mikrokontroler("ESP32", 0.24, 25);
    daftarKomponen[1] = new MotorRobstride("Robstride 06", 1.5, 180);
    daftarKomponen[2] = new Hidrolik("Piston Hidrolik", 2.0, 90);

    for (int i = 0; i < 3; i++) {
        daftarKomponen[i]->jalankanTugas();   
    }

    delete daftarKomponen[0];
    delete daftarKomponen[1];
    delete daftarKomponen[2];
    return 0;
}