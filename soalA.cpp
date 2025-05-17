#include <iostream>
#include <string>
using namespace std;

// === Class Mahasiswa ===
class Mahasiswa {
private:
    string nama;
    int NIM;
    float nilai;

public:
    Mahasiswa(string nama, int NIM) : nama(nama), NIM(NIM), nilai(0.0) {}

    // Deklarasi Dosen sebagai friend class untuk mengubah nilai
    friend class Dosen;

    // Method untuk mencetak data mahasiswa
    void cetak() const {
        cout << "Nama: " << nama << ", NIM: " << NIM << ", Nilai: " << nilai << endl;
    }
};



