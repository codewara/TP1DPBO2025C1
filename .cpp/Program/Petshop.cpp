#include <bits/stdc++.h>
using namespace std;

// Class Petshop
class Petshop {
private:
    int ID;
    string nama;
    string kategori;
    int harga;

public:
    // Constructor (initializer)
    Petshop () {
        ID = 0;
        nama = "";
        kategori = "";
        harga = 0;
    };

    // Constructor with parameter
    Petshop (int ID, string nama, string kategori, int harga) {
        this->ID = ID;
        this->nama = nama;
        this->kategori = kategori;
        this->harga = harga;
    }

    // SETTER and GETTER
    void setID(int ID) { this->ID = ID; }
    int getID() const { return ID; }

    void setNama(const string& nama) { this->nama = nama; }
    string getNama() const { return nama; }

    void setKategori(const string& kategori) { this->kategori = kategori; }
    string getKategori() const { return kategori; }

    void setHarga(int harga) { this->harga = harga; }
    int getHarga() const { return harga; }

    // Destructor
    ~Petshop () { }
};
