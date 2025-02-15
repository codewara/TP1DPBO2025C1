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

    // SETTER
    // Setter ID
    void setID (int ID) {
        this->ID = ID;
    }

    // Setter Nama
    void setNama (string nama) {
        this->nama = nama;
    }

    // Setter Kategori
    void setKategori (string kategori) {
        this->kategori = kategori;
    }

    // Setter Harga
    void setHarga (int harga) {
        this->harga = harga;
    }

    // GETTER
    // Getter ID
    int getID () {
        return ID;
    }

    // Getter Nama
    string getNama () {
        return nama;
    }

    // Getter Kategori
    string getKategori () {
        return kategori;
    }

    // Getter Harga
    int getHarga () {
        return harga;
    }

    // Destructor
    ~Petshop () { }
};
