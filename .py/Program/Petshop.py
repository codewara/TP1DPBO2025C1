# Class Petshop
class Petshop:
    # Atribut
    __ID = 0
    __nama = ""
    __kategori = ""
    __harga = 0

    # Method
    # Constructor
    def __init__(self, ID = 0, nama = "", kategori = "", harga = 0):
        self.__ID = ID
        self.__nama = nama
        self.__kategori = kategori
        self.__harga = harga

    # Setter and Getter
    def setID(self, ID):
        self.__ID = ID

    def getID(self):
        return self.__ID

    def setNama(self, nama):
        self.__nama = nama

    def getNama(self):
        return self.__nama

    def setKategori(self, kategori):
        self.__kategori = kategori

    def getKategori(self):
        return self.__kategori

    def setHarga(self, harga):
        self.__harga = harga

    def getHarga(self):
        return self.__harga