from Petshop import Petshop
from tabulate import tabulate

# Prosedur untuk menampilkan intro program
def intro():
    print("\n=================================================")
    print("||         Welcome to Petshop Program!         ||")
    print("=================================================\n")

# Fungsi utama program
def main():
    idx = 1 # Inisialisasi ID
    v = [] # Inisialisasi list untuk menyimpan data
    intro() # Menampilkan intro program

    while True: # Looping untuk menerima input user
        user_input = input("Petshop> ").strip().split(maxsplit=1) # Menerima input user
        input_cmd = user_input[0].upper() # Mengambil command dari input user
        str = user_input[1] if len(user_input) > 1 else "" # Mengambil string dari input user

        # Jika input user adalah "EXIT", maka program akan berhenti
        if input_cmd == "EXIT":
            break
        

        # Command "ADD" untuk menambahkan data
        if input_cmd == "ADD":
            # input data
            parts = str.split('"')
            nama = parts[1].strip()
            kategori = parts[3].strip()
            harga = int(parts[4].strip())

            sigma = Petshop(idx, nama, kategori, harga) # Membuat objek baru
            v.append(sigma); idx += 1 # Menambahkan data ke list dan increment ID
            print("A new data has been added.\n") # Menampilkan pesan


        # Command "DELETE" untuk menghapus data berdasarkan ID
        elif input_cmd == "DELETE":
            ID = int(str.strip()) # Mengambil ID dari input user
            v.pop(ID - 1) # Menghapus data berdasarkan ID
            print(f"Data with ID {ID} has been deleted.\n") # Menampilkan pesan


        # Command "UPDATE" untuk mengupdate data berdasarkan ID
        elif input_cmd == "UPDATE":
            # input data
            parts = str.split('"')
            ID = int(parts[0].strip())
            nama = parts[1].strip()
            kategori = parts[3].strip()
            harga = int(parts[4].strip())

            # Update data
            v[ID - 1].setNama(nama)
            v[ID - 1].setKategori(kategori)
            v[ID - 1].setHarga(harga)
            print(f"Data with ID {ID} has been updated.\n") # Menampilkan pesan


        # Command "SEARCH" untuk mencari data berdasarkan nama
        elif input_cmd == "SEARCH":
            # input data
            parts = str.split('"')
            nama = parts[1].strip()

            # Kondisi jika data kosong
            if not v:
                print("Data is empty!\n")

            # Kondisi jika data tidak kosong
            else:
                found = False
                for pet in v: # Loop sebanyak data yang ada
                    if pet.getNama() == nama:
                        found = True # Jika data ditemukan, flag found menjadi True
                        data = [[pet.getID(), pet.getNama(), pet.getKategori(), pet.getHarga()]] # Menambahkan data ke list
                        print(tabulate(data, headers=["ID", "NAMA", "KATEGORI", "HARGA"], tablefmt="grid")) # Tampilkan data
                        print("")
                        break
                
                # Kondisi jika data tidak ditemukan
                if not found:
                    print(f"Data with name '{nama}' not found!\n")


        # Command "SHOW" untuk menampilkan semua data
        elif input_cmd == "SHOW":
            # Kondisi jika data kosong
            if not v:
                print("Data is empty!\n")
            
            # Kondisi jika data tidak kosong
            else:
                data = [] # Inisialisasi list untuk menampilkan data
                for pet in v: # Loop sebanyak data yang ada
                    data.append([pet.getID(), pet.getNama(), pet.getKategori(), pet.getHarga()]) # Menambahkan data ke list
                print(tabulate(data, headers=["ID", "NAMA", "KATEGORI", "HARGA"], tablefmt="grid")) # Tampilkan data
                print(f"Displaying {len(v)} recocrd(s).\n") # Menampilkan jumlah data


        # Command "PETSHOP" untuk menampilkan command yang tersedia
        elif input_cmd == "PETSHOP":
            print("Command available:")
            print("1. ADD <nama> <kategori> <harga>")
            print("2. DELETE <ID>")
            print("3. UPDATE <ID> <nama> <kategori> <harga>")
            print("4. SEARCH <nama>")
            print("5. SHOW")
            print("6. EXIT\n")


        # Kondisi jika command tidak ditemukan
        else:
            print("Command not found!\n")

# Menjalankan program
if __name__ == "__main__":
    main()