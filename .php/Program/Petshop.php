<?php

// Class Petshop
class Petshop {
    // Atribut
    public $ID = 0;
    public $nama = '';
    public $kategori = '';
    public $harga = '';
    public $foto = '';

    // Constructor
    public function __construct($ID = 0, $nama = '', $kategori = '', $harga = 0, $foto = '') {
        $this->ID = $ID;
        $this->nama = $nama;
        $this->kategori = $kategori;
        $this->harga = $harga;
        $this->foto = $foto;
    }

    // SETTER & GETTER
    public function setID ($ID) { $this->ID = $ID; }
    public function getID () { return $this->ID; }

    public function setNama ($nama) { $this->nama = $nama; }
    public function getNama () { return $this->nama; }

    public function setKategori ($kategori) { $this->kategori = $kategori; }
    public function getKategori () { return $this->kategori; }

    public function setHarga ($harga) { $this->harga = $harga; }
    public function getHarga () { return $this->harga; }

    public function setFoto ($foto) { $this->foto = $foto; }
    public function getFoto () { return $this->foto; }
}

?>