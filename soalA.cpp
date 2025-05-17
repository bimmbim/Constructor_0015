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

// === Class Dosen ===
class Dosen {
private:
    string nama;
    string NIDN;
    string pangkat;
    float gaji;

public:
    Dosen(string nama, string NIDN, string pangkat, float gaji) : nama(nama), NIDN(NIDN), pangkat(pangkat), gaji(gaji) {}

    // Method untuk memberi nilai kepada mahasiswa
    void beriNilai(Mahasiswa* m, float nilai) {
        m->nilai = nilai;
    }

    // Friend class untuk Staff
    friend class Staff;

    // Deklarasi friend function untuk melihat gaji dosen
    friend void lihatGajiDosen(Dosen* d);
};

// === Class Staff ===
class Staff {
private:
    string nama;
    string IDStaff;
    float gaji;

public:
    Staff(string nama, string IDStaff, float gaji) : nama(nama), IDStaff(IDStaff), gaji(gaji) {}

    // Method untuk mengubah pangkat dosen menggunakan pointer
    void ubahPangkat(Dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

    // Friend function untuk melihat gaji staff
    friend void lihatGajiStaff(Staff* s);
};

// Friend Function untuk melihat gaji dosen
void lihatGajiDosen(Dosen* d) {
    cout << "Gaji Dosen: " << d->gaji << endl;
}

// Friend Function untuk melihat gaji staff
void lihatGajiStaff(Staff* s) {
    cout << "Gaji Staff: " << s->gaji << endl;
}

int main() {
    // Membuat objek Mahasiswa
    Mahasiswa mhs("Budi", 12345);
    mhs.cetak();

    // Membuat objek Dosen
    Dosen dsn("Dr. Ahmad", "98765", "Lektor", 15000000);
    dsn.beriNilai(&mhs, 85.5);
    mhs.cetak();

    // Membuat objek Staff
    Staff stf("Siti", "ST123", 5000000);

    // Mengubah pangkat dosen
    stf.ubahPangkat(&dsn, "Profesor");

    // Melihat gaji dosen dan staff
    lihatGajiDosen(&dsn);
    lihatGajiStaff(&stf);

    return 0;
}