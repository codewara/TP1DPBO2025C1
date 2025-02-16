#include "Petshop.cpp"

// global variable untuk menentukan panjang kolom
int colID = 2, colName = 4, colCategory = 8, colPrice = 5;

// fungsi untuk menampilkan intro program
void intro () {
    cout << "\n=================================================\n";
    cout << "||         Welcome to Petshop Program!         ||\n";
    cout << "=================================================\n\n";
}

// prosedur untuk menentukan panjang kolom
void colCheck (vector<Petshop> v) {
    colID = 2, colName = 4, colCategory = 8, colPrice = 5; // reset panjang kolom

    // loop semua data
    for (int i = 0; i < v.size(); i++) {
        colID = max(colID, static_cast<int>(to_string(v[i].getID()).length())); if (colID % 2 == 1) colID++; // cari ID terpanjang, jika ganjil tambahkan 1
        colName = max(colName, static_cast<int>(v[i].getNama().length())); if (colName % 2 == 1) colName++; // cari nama terpanjang, jika ganjil tambahkan 1
        colCategory = max(colCategory, static_cast<int>(v[i].getKategori().length())); if (colCategory % 2 == 1) colCategory++; // cari kategori terpanjang, jika ganjil tambahkan 1
        colPrice = max(colPrice, static_cast<int>(to_string(v[i].getHarga()).length())); if (colPrice % 2 == 0) colPrice++; // cari harga terpanjang, jika genap tambahkan 1
    }
}

// prosedur untuk menampilkan header
void header (int col1, int col2, int col3, int col4) {
    cout << "+-"; for (int i = 0; i < col1; i++) cout << "-";
    cout << "-+-"; for (int i = 0; i < col2; i++) cout << "-";
    cout << "-+-"; for (int i = 0; i < col3; i++) cout << "-";
    cout << "-+-"; for (int i = 0; i < col4; i++) cout << "-";
    cout << "-+" << endl;
    cout << "| "; for (int i = 0; i < col1 - 2; i+=2) cout << " ";
    cout << "ID"; for (int i = 0; i < col1 - 2; i+=2) cout << " ";
    cout << " | "; for (int i = 0; i < col2 - 4; i+=2) cout << " ";
    cout << "NAMA"; for (int i = 0; i < col2 - 4; i+=2) cout << " ";
    cout << " | "; for (int i = 0; i < col3 - 8; i+=2) cout << " ";
    cout << "KATEGORI"; for (int i = 0; i < col3 - 8; i+=2) cout << " ";
    cout << " | "; for (int i = 0; i < col4 - 5; i+=2) cout << " ";
    cout << "HARGA"; for (int i = 0; i < col4 - 5; i+=2) cout << " ";
    cout << " |" << endl;
    cout << "+="; for (int i = 0; i < col1; i++) cout << "=";
    cout << "=+="; for (int i = 0; i < col2; i++) cout << "=";
    cout << "=+="; for (int i = 0; i < col3; i++) cout << "=";
    cout << "=+="; for (int i = 0; i < col4; i++) cout << "=";
    cout << "=+" << endl;
}

// prosedur untuk menampilkan footer
void footer (int col1, int col2, int col3, int col4) {
    cout << "+-"; for (int i = 0; i < col1; i++) cout << "-";
    cout << "-+-"; for (int i = 0; i < col2; i++) cout << "-";
    cout << "-+-"; for (int i = 0; i < col3; i++) cout << "-";
    cout << "-+-"; for (int i = 0; i < col4; i++) cout << "-";
    cout << "-+" << endl;
}

// prosedur untuk menampilkan baris data
void printRow (int ID, string nama, string kategori, int harga, int col1, int col2, int col3, int col4) {
    cout << "| "; for (int i = 0; i < col1 - to_string(ID).length(); i++) cout << " ";
    cout << ID << " | " << nama; for (int i = 0; i < col2 - nama.length(); i++) cout << " ";
    cout << " | " << kategori; for (int i = 0; i < col3 - kategori.length(); i++) cout << " ";
    cout << " | "; for (int i = 0; i < col4 - to_string(harga).length(); i++) cout << " ";
    cout << harga << " |" << endl;
}

// fungsi utama
int main () {
    int idx = 1; // inisialisasi ID
    vector<Petshop> v; // inisialisasi vector
    string input; // inisialisasi input
    intro (); // tampilkan intro program

    do { // loop selama input tidak "EXIT"
        cout << "Petshop> "; cin >> input; // input command
        transform(input.begin(), input.end(), input.begin(), ::toupper); // ubah input menjadi huruf kapital

        // Kondisi jika input bukan "EXIT"
        if (input != "EXIT") {
            Petshop sigma;
            int harga;
            string nama, kategori;

            // Command "ADD" untuk menambahkan data
            if (input == "ADD") {
                // input data
                cin.ignore(); getline(cin, nama, '"'); getline(cin, nama, '"');
                cin.ignore(); getline(cin, kategori, '"'); getline(cin, kategori, '"');
                cin >> harga;
                sigma = Petshop (idx, nama, kategori, harga); // inisialisasi data
                v.push_back(sigma); idx++; // tambahkan data ke vector dan increment ID
                cout << "A new data has been added.\n\n"; // tampilkan pesan
            }
            
            // Command "DELETE" untuk menghapus data berdasarkan ID
            else if (input == "DELETE") {
                // input ID
                int ID; cin >> ID;
                v.erase(v.begin() + ID - 1); // hapus data berdasarkan ID
                cout << "Data with ID " << ID << " has been deleted.\n\n"; // tampilkan pesan
            }
            
            // Command "UPDATE" untuk mengubah data berdasarkan ID
            else if (input == "UPDATE") {
                // input data
                int ID; cin >> ID;
                cin.ignore(); getline(cin, nama, '"'); getline(cin, nama, '"');
                cin.ignore(); getline(cin, kategori, '"'); getline(cin, kategori, '"');
                cin >> harga;

                // update data
                v[ID - 1].setNama(nama);
                v[ID - 1].setKategori(kategori);
                v[ID - 1].setHarga(harga);
                cout << "Data with ID " << ID << " has been updated.\n\n"; // tampilkan pesan
            }

            // Command "SEARCH" untuk mencari data berdasarkan nama
            else if (input == "SEARCH") {
                // input nama
                cin.ignore(); getline(cin, nama, '"'); getline(cin, nama, '"');

                // kondisi jika data kosong
                if (v.size() == 0) cout << "Data is empty!" << endl;

                // kondisi jika data tidak kosong
                else {
                    int i = 0; bool found = false; // loop semua data
                    while (i < v.size()) {
                        if (v[i].getNama() == nama) { // jika data ditemukan
                            found = true; // set panjang kolom
                            int srcID = max(2, static_cast<int>(to_string(v[i].getID()).length())); if (srcID % 2 == 1) srcID++;
                            int srcName = max(4, static_cast<int>(v[i].getNama().length())); if (srcName % 2 == 1) srcName++;
                            int srcCategory = max(8, static_cast<int>(v[i].getKategori().length())); if (srcCategory % 2 == 1) srcCategory++;
                            int srcPrice = max(5, static_cast<int>(to_string(v[i].getHarga()).length())); if (srcPrice % 2 == 0) srcPrice++;
                            header (srcID, srcName, srcCategory, srcPrice); // tampilkan header
                            printRow (v[i].getID(), v[i].getNama(), v[i].getKategori(), v[i].getHarga(), srcID, srcName, srcCategory, srcPrice); // tampilkan data
                            footer (srcID, srcName, srcCategory, srcPrice); cout << "\n"; // tampilkan footer
                            break; // keluar dari loop
                        } i++; // increment
                    }
                    
                    // kondisi jika data tidak ditemukan
                    if (!found) cout << "Data with name '" << nama << "' not found!\n\n";
                }
            }
            
            // Command "SHOW" untuk menampilkan semua data yang ada
            else if (input == "SHOW") {
                colCheck (v); // set panjang kolom

                // kondisi jika data kosong
                if (v.size () == 0) cout << "Data is empty!\n\n";

                // kondisi jika data tidak kosong
                else {
                    header (colID, colName, colCategory, colPrice); // tampilkan header
                    for (int i = 0; i < v.size(); i++) { // loop semua data dan tampilkan
                        printRow (v[i].getID(), v[i].getNama(), v[i].getKategori(), v[i].getHarga(), colID, colName, colCategory, colPrice);
                    } footer (colID, colName, colCategory, colPrice); // tampilkan footer
                    cout << "Displaying " << v.size() << " record(s).\n\n"; // tampilkan jumlah data yang ditampilkan
                }
            }
            
            // Command "PETSHOP" untuk menampilkan semua command yang tersedia
            else if (input == "PETSHOP") {
                cout << "Command available:\n";
                cout << "1. ADD <nama> <kategori> <harga>\n";
                cout << "2. DELETE <ID>\n";
                cout << "3. UPDATE <ID> <nama> <kategori> <harga>\n";
                cout << "4. SEARCH <nama>\n";
                cout << "5. SHOW\n";
                cout << "6. EXIT\n\n";
            }

            // Kondisi jika command tidak ditemukan
            else cout << "Command not found!\n\n";
        }
    } while (input != "EXIT"); // Command "EXIT" untuk keluar dari program
}