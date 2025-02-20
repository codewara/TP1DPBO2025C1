// Class Petshop
public class Petshop {
    // Atribut
    private int ID;
    private String nama;
    private String kategori;
    private int harga;

    // Constructor (initializer)
    public Petshop() {
        this.ID = 0;
        this.nama = "";
        this.kategori = "";
        this.harga = 0;
    }

    // Constructor dengan parameter
    public Petshop(int ID, String nama, String kategori, int harga) {
        this.ID = ID;
        this.nama = nama;
        this.kategori = kategori;
        this.harga = harga;
    }

    // SETTER & GETTER
    public void setID(int ID) { this.ID = ID; }
    public int getID() { return this.ID; }

    public void setNama(String nama) { this.nama = nama; }
    public String getNama() { return this.nama; }

    public void setKategori(String kategori) { this.kategori = kategori; }
    public String getKategori() { return this.kategori; }

    public void setHarga(int harga) { this.harga = harga; }
    public int getHarga() { return this.harga; }
}