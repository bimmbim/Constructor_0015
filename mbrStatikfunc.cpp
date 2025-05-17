#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    static int nim;
    int id;
    string nama;

public:
    void setID();
    void printAll();

    static void setNim(int pNim); // Definisi Function
    static int getNim(); // Definisi Function

    mahasiswa(string pNama) : nama(pNama) { setID(); }
};

int mahasiswa::nim = 0;

void mahasiswa::setID() {
    id = ++nim;
}








