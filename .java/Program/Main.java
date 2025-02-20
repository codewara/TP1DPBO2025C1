import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // global variable untuk menentukan panjang kolom
    static int colID = 2, colName = 4, colCategory = 8, colPrice = 5;

    // Method untuk menampilkan intro program
    public static void intro() {
        System.out.println("\n=================================================");
        System.out.println("||         Welcome to Petshop Program!         ||");
        System.out.println("=================================================\n");
    }

    // Method untuk menentukan panjang kolom
    public static void colCheck(ArrayList<Petshop> v) {
        colID = 2; colName = 4; colCategory = 8; colPrice = 5; // reset panjang kolom

        // loop semua data
        for (Petshop pet : v) {
            colID = Math.max(colID, String.valueOf(pet.getID()).length()); if (colID % 2 == 1) colID++; // cari ID terpanjang, jika ganjil tambahkan 1
            colName = Math.max(colName, pet.getNama().length()); if (colName % 2 == 1) colName++; // cari nama terpanjang, jika ganjil tambahkan 1
            colCategory = Math.max(colCategory, pet.getKategori().length()); if (colCategory % 2 == 1) colCategory++; // cari kategori terpanjang, jika ganjil tambahkan 1
            colPrice = Math.max(colPrice, String.valueOf(pet.getHarga()).length()); if (colPrice % 2 == 0) colPrice++; // cari harga terpanjang, jika genap tambahkan 1
        }
    }

    // Method untuk menampilkan header
    public static void header(int col1, int col2, int col3, int col4) {
        System.out.print("+-"); for (int i = 0; i < col1; i++) System.out.print("-");
        System.out.print("-+-"); for (int i = 0; i < col2; i++) System.out.print("-");
        System.out.print("-+-"); for (int i = 0; i < col3; i++) System.out.print("-");
        System.out.print("-+-"); for (int i = 0; i < col4; i++) System.out.print("-");
        System.out.println("-+");
        System.out.print("| "); for (int i = 0; i < col1 - 2; i += 2) System.out.print(" ");
        System.out.print("ID"); for (int i = 0; i < col1 - 2; i += 2) System.out.print(" ");
        System.out.print(" | "); for (int i = 0; i < col2 - 4; i += 2) System.out.print(" ");
        System.out.print("NAMA"); for (int i = 0; i < col2 - 4; i += 2) System.out.print(" ");
        System.out.print(" | "); for (int i = 0; i < col3 - 8; i += 2) System.out.print(" ");
        System.out.print("KATEGORI"); for (int i = 0; i < col3 - 8; i += 2) System.out.print(" ");
        System.out.print(" | "); for (int i = 0; i < col4 - 5; i += 2) System.out.print(" ");
        System.out.print("HARGA"); for (int i = 0; i < col4 - 5; i += 2) System.out.print(" ");
        System.out.println(" |");
        System.out.print("+="); for (int i = 0; i < col1; i++) System.out.print("=");
        System.out.print("=+="); for (int i = 0; i < col2; i++) System.out.print("=");
        System.out.print("=+="); for (int i = 0; i < col3; i++) System.out.print("=");
        System.out.print("=+="); for (int i = 0; i < col4; i++) System.out.print("=");
        System.out.println("=+");
    }

    // Method untuk menampilkan footer
    public static void footer(int col1, int col2, int col3, int col4) {
        System.out.print("+-"); for (int i = 0; i < col1; i++) System.out.print("-");
        System.out.print("-+-"); for (int i = 0; i < col2; i++) System.out.print("-");
        System.out.print("-+-"); for (int i = 0; i < col3; i++) System.out.print("-");
        System.out.print("-+-"); for (int i = 0; i < col4; i++) System.out.print("-");
        System.out.println("-+");
    }

    // Method untuk menampilkan baris data
    public static void printRow(int ID, String nama, String kategori, int harga, int col1, int col2, int col3, int col4) {
        System.out.print("| "); for (int i = 0; i < col1 - String.valueOf(ID).length(); i++) System.out.print(" ");
        System.out.print(ID + " | " + nama); for (int i = 0; i < col2 - nama.length(); i++) System.out.print(" ");
        System.out.print(" | " + kategori); for (int i = 0; i < col3 - kategori.length(); i++) System.out.print(" ");
        System.out.print(" | "); for (int i = 0; i < col4 - String.valueOf(harga).length(); i++) System.out.print(" ");
        System.out.println(harga + " |");
    }

    // Method utama program
    public static void main(String[] args) {
        int idx = 1; // Inisialisasi ID
        ArrayList<Petshop> v = new ArrayList<>(); // Inisialisasi arraylist
        Scanner scanner = new Scanner(System.in); // Inisialisasi scanner
        intro(); // Menampilkan intro program

        while (true) { // Loop untuk setiap input
            System.out.print("Petshop> ");
            String input = scanner.nextLine().trim();
            String[] userInput = input.split(" ", 2);
            String inputCmd = userInput[0].toUpperCase();
            String str = userInput.length > 1 ? userInput[1] : "";

            // Kondisi jika input command adalah "EXIT"
            if (inputCmd.equals("EXIT")) break;

            // Command "ADD" untuk menambahkan data
            if (inputCmd.equals("ADD")) {
                // input data
                String[] parts = str.split("\"");
                String nama = parts[1].trim();
                String kategori = parts[3].trim();
                int harga = Integer.parseInt(parts[4].trim());

                Petshop sigma = new Petshop(idx, nama, kategori, harga); // buat objek baru
                v.add(sigma); idx++; // tambahkan data dan increment ID
                System.out.println("A new data has been added.\n"); // tampikan pesan
            }

            // Command "DELETE" untuk menghapus data
            else if (inputCmd.equals("DELETE")) {
                int ID = Integer.parseInt(str.trim()); // input ID
                v.remove(ID - 1); // hapus data
                System.out.println("Data with ID " + ID + " has been deleted.\n"); // tampikan pesan
            }

            // Command "UPDATE" untuk mengupdate data
            else if (inputCmd.equals("UPDATE")) {
                // input data
                String[] parts = str.split("\"");
                int ID = Integer.parseInt(parts[0].trim());
                String nama = parts[1].trim();
                String kategori = parts[3].trim();
                int harga = Integer.parseInt(parts[4].trim());

                // update data
                Petshop pet = v.get(ID - 1);
                pet.setNama(nama);
                pet.setKategori(kategori);
                pet.setHarga(harga);
                System.out.println("Data with ID " + ID + " has been updated.\n"); // tampikan pesan
            }

            // Command "SEARCH" untuk mencari data
            else if (inputCmd.equals("SEARCH")) {
                // input nama
                String[] parts = str.split("\"");
                String nama = parts[1].trim();

                // Kondisi jika data kosong
                if (v.isEmpty()) System.out.println("Data is empty!\n");

                // Kondisi jika data tidak kosong
                else {
                    boolean found = false;
                    for (Petshop pet : v) { // loop untuk setiap data
                        if (pet.getNama().equals(nama)) {
                            found = true; // set found menjadi true jika data ditemukan
                            int srcID = Math.max(2, String.valueOf(pet.getID()).length()); if (srcID % 2 == 1) srcID++;
                            int srcName = Math.max(4, pet.getNama().length()); if (srcName % 2 == 1) srcName++;
                            int srcCategory = Math.max(8, pet.getKategori().length()); if (srcCategory % 2 == 1) srcCategory++;
                            int srcPrice = Math.max(5, String.valueOf(pet.getHarga()).length()); if (srcPrice % 2 == 0) srcPrice++;
                            header(srcID, srcName, srcCategory, srcPrice); // tampilkan header
                            printRow(pet.getID(), pet.getNama(), pet.getKategori(), pet.getHarga(), srcID, srcName, srcCategory, srcPrice); // tampilkan data
                            footer(srcID, srcName, srcCategory, srcPrice); // tampilkan footer
                            System.out.println("");
                        }
                    }

                    // Kondisi jika data tidak ditemukan
                    if (!found) System.out.println("Data with name '" + nama + "' not found!\n");
                }
            }

            // Command "SHOW" untuk menampilkan data
            else if (inputCmd.equals("SHOW")) {
                colCheck(v); // cek panjang kolom

                // Kondisi jika data kosong
                if (v.isEmpty()) System.out.println("Data is empty!\n");

                // Kondisi jika data tidak kosong
                else {
                    header(colID, colName, colCategory, colPrice); // tampilkan header
                    for (Petshop pet : v) { // loop untuk setiap data
                        printRow(pet.getID(), pet.getNama(), pet.getKategori(), pet.getHarga(), colID, colName, colCategory, colPrice); // tampilkan data
                    } footer(colID, colName, colCategory, colPrice); // tampilkan footer
                    System.out.println("Displaying " + v.size() + " record(s).\n"); // tampilkan jumlah data
                }
            }

            // Command "PETSHOP" untuk menampilkan command yang tersedia
            else if (inputCmd.equals("PETSHOP")) {
                System.out.println("Command available:");
                System.out.println("1. ADD <nama> <kategori> <harga>");
                System.out.println("2. DELETE <ID>");
                System.out.println("3. UPDATE <ID> <nama> <kategori> <harga>");
                System.out.println("4. SEARCH <nama>");
                System.out.println("5. SHOW");
                System.out.println("6. EXIT\n");
            }

            // Kondisi jika command tidak ditemukan
            else System.out.println("Command not found!\n");
        }

        scanner.close(); // tutup scanner
    }
}