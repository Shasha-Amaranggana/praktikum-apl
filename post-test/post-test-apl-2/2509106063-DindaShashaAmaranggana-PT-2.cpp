#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
using namespace std;

/* STRUCT ADMIN DAN CRUD
════════════════════════════════════════════════════*/
struct Akun {
    string username;
    string password;
    string role;
    int saldo;};

struct Ebook {
    int id;
    string judul;
    string penulis;
    int tahun;
    string genre;
    int harga;
};

struct EbookUser {
    string username;
    Ebook buku;
};

/* MAIN
════════════════════════════════════════════════════*/
int main() {
    SetConsoleOutputCP(65001);

    string pilihMenu;
    string jawabNama;
    string jawabPassword;
    string pilihMenuAdmin;
    string pilihMenuUser;
    bool userAda;
    int IdBuku;
    string JudulBuku;
    string PenulisBuku;
    int TahunBuku;
    string GenreBuku;
    int HargaBuku;
    bool bukuAda;
    int idEdit;
    int hargaBaru;
    int idHapus;
    int idPesan;
    bool bukuUser;
    bool sudahBeli;
    int nominal;

    Akun akun[100] = {
        {"Shasha", "063", "admin", 0},
        {"Aura", "015", "user", 100000}};

    Ebook katalog[100] = {
        {1, "Magnus Chase 1", "Rick Riordan", 2015, "Fantasi", 70000},
        {2, "The Walled City", "Ryan Graudin", 2014, "Drama", 50000},
        {3, "City of Lost Souls", "Cassandra Clare", 2012, "Fantasi", 60000},
        {4, "The Trials of Apollo 2", "Rick Riordan", 2017, "Fantasi", 50000},
        {5, "The Trials of Apollo 3", "Rick Riordan", 2018, "Fantasi", 50000},};

    EbookUser ebookUser[100];
    
    int jumlahUser = 2;
    int jumlahBuku = 5;
    int jumlahEbookUser = 0;
    int salah = 0;

    /* PROGRAM UTAMA
    ════════════════════════════════════════════════════*/
    while (true) {
        system("cls");
        cout << "══════════════════════════════════════════════════════════════════════" << endl;
        cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
        cout << "══════════════════════════════════════════════════════════════════════" << endl;
        cout << "     ══════════════════════════════════════════════════════════     " << endl;
        cout << setw((70 + 14) / 2) << "Selamat Datang" << endl;
        cout << "     ══════════════════════════════════════════════════════════     " << endl;
        cout << "\n     1 | Login" << endl;
        cout << "     2 | Register" << endl;
        cout << "     3 | Keluar" << endl;
        cout << "\n     ╰┈➤  Pilih menu: "; cin >> pilihMenu;


        /* A. LOGIN
        ════════════════════════════════════════════════════*/
        if (pilihMenu == "1") {
            system("cls");
            cout << "══════════════════════════════════════════════════════════════════════" << endl;
            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
            cout << "══════════════════════════════════════════════════════════════════════" << endl;
            cout << "     ══════════════════════════════════════════════════════════     " << endl;
            cout << setw((70 + 16) / 2) << "Login Akun Anda" << endl;
            cout << "     ══════════════════════════════════════════════════════════     " << endl;
            cout << "\n     Username: "; cin >> jawabNama;
            cout << "     Password: "; cin >> jawabPassword;

            int indeksLogin = -1;
            userAda = false;
            for (int i = 0; i < jumlahUser; i++) {
                if (akun[i].username == jawabNama && akun[i].password == jawabPassword) {
                    userAda = true;
                    indeksLogin = i;
                    break;}}

            if (userAda) {
                salah = 0;
                cout << "" << endl;
                cout << setw((70 + 22) / 2) << "=====================" << endl;
                cout << setw((70 + 28) / 2) << "Login berhasil! Selamat datang, " << jawabNama << "." << endl;
                cout << setw((70 + 22) / 2) << "=====================" << endl;
                cout << "" << endl;
                system("pause");


                /* 1. MENU ADMIN (CRUD)
                ════════════════════════════════════════════════════*/
                if (akun[indeksLogin].role == "admin") {
                    while (true) {
                        system("cls");
                        cout << "══════════════════════════════════════════════════════════════════════" << endl;
                        cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                        cout << "══════════════════════════════════════════════════════════════════════" << endl;
                        cout << "     ══════════════════════════════════════════════════════════     " << endl;
                        cout << setw((70 + 6) / 2) << "Halo, admin " << jawabNama << endl;
                        cout << "     ══════════════════════════════════════════════════════════     " << endl;
                        cout << setw((70 + 22) / 2) << "=====================" << endl;
                        cout << setw((70 + 2) / 2) << "Saldo: " << akun[indeksLogin].saldo << endl;
                        cout << setw((70 + 22) / 2) << "=====================" << endl;
                        cout << "\n     1 | Menu Katalog E-Book" << endl;
                        cout << "     2 | Tambahkan E-Book Baru" << endl;
                        cout << "     3 | Ubah Harga E-Book" << endl;
                        cout << "     4 | Hapus E-Book" << endl;
                        cout << "     5 | Logout" << endl;
                        cout << "\n     ╰┈➤  Pilih menu: "; cin >> pilihMenuAdmin;
                    
                        /* a. MENU ADMIN READ (Katalog E-Book)
                        ════════════════════════════════════════════════════*/
                        if (pilihMenuAdmin == "1") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 20) / 2) << "Menu Katalog E-Book" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            if (jumlahBuku == 0) {
                                cout << "" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << setw((70 + 28) / 2) << "Katalog E-Book Belum Terisi" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << "" << endl;}
                            else {
                                cout << "ID | JUDUL                    | PENULIS             | TAHUN   | GENRE     | HARGA" << endl;
                                cout << "---+--------------------------+---------------------+---------+-----------+--------" << endl;
                                for(int i = 0; i < jumlahBuku; i++) {
                                    cout << left
                                        << setw(3) << katalog[i].id << "| "<< setw(25) << katalog[i].judul << "| "
                                        << setw(20) << katalog[i].penulis << "| " << setw(8) << katalog[i].tahun << "| "
                                        << setw(10) << katalog[i].genre << "| " << setw(10) << katalog[i].harga
                                        << endl;}
                                    cout << right;}
                            cout << "" << endl;
                            system("pause");}

                        /* b. MENU ADMIN CREATE (Tambah E-Book)
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuAdmin == "2") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 22) / 2) << "Tambahkan E-Book Baru" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            cout << "\n     ID: "; cin >> IdBuku;
                            cin.ignore();
                            cout << "     Judul: "; getline(cin, JudulBuku);
                            cout << "     Penulis: "; getline(cin, PenulisBuku);
                            cout << "     Tahun: "; cin >> TahunBuku;
                            cout << "     Genre: "; cin >> GenreBuku;
                            cout << "     Harga: "; cin >> HargaBuku;

                            bukuAda = false;
                            for (int i = 0; i < jumlahBuku; i++) {
                                if (katalog[i].id == IdBuku) {
                                    bukuAda = true;
                                    cout << "" << endl;
                                    cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                    cout << setw((70 + 24) / 2) << "ID e-book telah tersedia!" << endl;
                                    cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                    cout << "" << endl;
                                    break;}}
                            if (!bukuAda) {
                                katalog[jumlahBuku].id = IdBuku;
                                katalog[jumlahBuku].judul = JudulBuku;
                                katalog[jumlahBuku].penulis = PenulisBuku;
                                katalog[jumlahBuku].tahun = TahunBuku;
                                katalog[jumlahBuku].genre = GenreBuku;
                                katalog[jumlahBuku].harga = HargaBuku;
                                jumlahBuku++;
                                cout << "" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << setw((70 + 30) / 2) << "E-Book berhasil ditambahkan!" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << "" << endl;}
                            system("pause");}

                        /* c. MENU ADMIN UPDATE (Edit Harga E-Book)
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuAdmin == "3") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 18) / 2) << "Ubah Harga E-Book" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            cout << "     Masukkan ID e-book yang ingin diubah harganya: "; cin >> idEdit;

                            bukuAda = false;
                            for (int i = 0; i < jumlahBuku; i++) {
                                if (katalog[i].id == idEdit) {
                                    bukuAda = true;
                                    cout << "";
                                    cout << "\n     Judul E-Book : " << katalog[i].judul << endl;
                                    cout << "     Harga lama : " << katalog[i].harga << endl;
                                    cout << "";
                                    cout << "\n     Masukkan harga baru: "; cin >> hargaBaru;
                                    katalog[i].harga = hargaBaru;
                                    cout << "" << endl;
                                    cout << setw((70 + 22) / 2) << "=====================" << endl;
                                    cout << setw((70 + 34) / 2) << "Harga e-book berhasil diperbarui!" << endl;
                                    cout << setw((70 + 22) / 2) << "=====================" << endl;
                                    cout << "" << endl;
                                    break;}}
                            if (!bukuAda) {
                                cout << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << setw((70 + 28) / 2) << "ID e-book tidak ditemukan!" << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << endl;}
                            system("pause");}

                        /* d. MENU ADMIN DELETE (Hapus E-Book)
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuAdmin == "4") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 14) / 2) << "Hapus E-Book" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            cout << "     Masukkan ID e-book yang ingin dihapus: "; cin >> idHapus;

                            bukuAda = false;
                            for (int i = 0; i < jumlahBuku; i++) {
                                if (katalog[i].id == idHapus) {
                                    bukuAda = true;
                                    cout << "" << endl;
                                    cout << "\n     ID  : " << katalog[i].id << endl;
                                    cout << "     Judul E-Book : " << katalog[i].judul << endl;
                                    cout << "" << endl;
                                
                                    for (int j = i; j < jumlahBuku - 1; j++) {
                                        katalog[j] = katalog[j + 1];
                                    }
                                    jumlahBuku--;

                                    cout << "" << endl;
                                    cout << setw((70 + 22) / 2) << "=====================" << endl;
                                    cout << setw((70 + 26) / 2) << "E-book berhasil dihapus!" << endl;
                                    cout << setw((70 + 22) / 2) << "=====================" << endl;
                                    cout << "" << endl;
                                    break;}}
                            if (!bukuAda) {
                                cout << "" << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << setw((70 + 28) / 2) << "ID e-book tidak ditemukan!" << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << "" << endl;}
                            system("pause");}


                        /* e. MENU ADMIN LOGOUT
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuAdmin == "5") {
                            cout << "" << endl;
                            cout << setw((70 + 22) / 2) << "=====================" << endl;
                            cout << setw((70 + 18) / 2) << "Logout berhasil!" << endl;
                            cout << setw((70 + 22) / 2) << "=====================" << endl;
                            cout << "" << endl;
                            system("pause");
                            break;}

                        /* f. SALAH INPUT MENU ADMIN
                        ════════════════════════════════════════════════════*/
                        else {
                            cout << "" << endl;
                            cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                            cout << setw((70 + 30) / 2) << "Pilihan menu tidak tersedia!" << endl;
                            cout << setw((70 + 34) / 2) << "---------------------------------" << endl; 
                            cout << "" << endl;  
                            system("pause");}}}


                /* 2. MENU USER (CRUD)
                ════════════════════════════════════════════════════*/
                else {
                    while (true) {
                        system("cls");
                        cout << "══════════════════════════════════════════════════════════════════════" << endl;
                        cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                        cout << "══════════════════════════════════════════════════════════════════════" << endl;
                        cout << "     ══════════════════════════════════════════════════════════     " << endl;
                        cout << setw((70 + 2) / 2) << "Halo, " << jawabNama << endl;
                        cout << "     ══════════════════════════════════════════════════════════     " << endl;
                        cout << setw((70 + 22) / 2) << "=====================" << endl;
                        cout << setw((70 + 2) / 2) << "Saldo: " << akun[indeksLogin].saldo << endl;
                        cout << setw((70 + 22) / 2) << "=====================" << endl;
                        cout << "\n     1 | Menu Katalog E-Book" << endl;
                        cout << "     2 | Pesan E-Book" << endl;
                        cout << "     3 | E-Book Anda" << endl;
                        cout << "     4 | Topup Saldo" << endl;
                        cout << "     5 | Logout" << endl;
                        cout << "\n     ╰┈➤  Pilih menu: "; cin >> pilihMenuUser;
                    
                        /* a. MENU USER READ (Katalog E-Book)
                        ════════════════════════════════════════════════════*/
                        if (pilihMenuUser == "1") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 20) / 2) << "Menu Katalog E-Book" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            if (jumlahBuku == 0) {
                                cout << "" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << setw((70 + 28) / 2) << "Katalog E-Book Belum Terisi" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << "" << endl;}
                            else {
                                cout << "ID | JUDUL                    | PENULIS             | TAHUN   | GENRE     | HARGA" << endl;
                                cout << "---+--------------------------+---------------------+---------+-----------+--------" << endl;
                                for(int i = 0; i < jumlahBuku; i++) {
                                    cout << left
                                        << setw(3) << katalog[i].id << "| "<< setw(25) << katalog[i].judul << "| "
                                        << setw(20) << katalog[i].penulis << "| " << setw(8) << katalog[i].tahun << "| "
                                        << setw(10) << katalog[i].genre << "| " << setw(10) << katalog[i].harga
                                        << endl;}
                                    cout << right;}
                            cout << "" << endl;
                            system("pause");}

                        /* b. MENU USER CREATE (Pesan E-Book)
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuUser == "2") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 14) / 2) << "Pesan E-Book" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            cout << "     Masukkan ID e-book yang ingin dipesan: "; cin >> idPesan;

                            bukuAda = false;
                            for (int i = 0; i < jumlahBuku; i++) {
                                if (katalog[i].id == idPesan) {
                                    bukuAda = true;

                                    sudahBeli = false;
                                    for(int i = 0; i < jumlahEbookUser; i++){
                                        if(ebookUser[i].username == jawabNama &&
                                        ebookUser[i].buku.id == idPesan){
                                            sudahBeli = true;
                                            break;}}

                                    if (sudahBeli) {
                                        cout << endl;
                                        cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                        cout << setw((70 + 32) / 2) << "Anda sudah membeli e-book ini!" << endl;
                                        cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                        cout << endl;}
                                    else {
                                        if (akun[indeksLogin].saldo >= katalog[i].harga) {
                                            akun[indeksLogin].saldo -= katalog[i].harga;
                                            akun[0].saldo += katalog[i].harga;
                                            ebookUser[jumlahEbookUser].username = jawabNama;
                                            ebookUser[jumlahEbookUser].buku = katalog[i];

                                            jumlahEbookUser++;
                                            cout << "" << endl;
                                            cout << "\n     ID  : " << katalog[i].id << endl;
                                            cout << "     Judul E-Book : " << katalog[i].judul << endl;
                                            cout << "" << endl;
                                            cout << "" << endl;
                                            cout << setw((70 + 22) / 2) << "=====================" << endl;
                                            cout << setw((70 + 24) / 2) << "E-book berhasil dibeli!" << endl;
                                            cout << setw((70 + 22) / 2) << "=====================" << endl;
                                            cout << "" << endl;}
                                        else {
                                            cout << endl;
                                            cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                            cout << setw((70 + 24) / 2) << "Saldo anda tidak cukup!" << endl;
                                            cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                            cout << endl;}
                                        break;}}}
                            if (!bukuAda) {
                                cout << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << setw((70 + 28) / 2) << "ID e-book tidak ditemukan!" << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << endl;}
                            system("pause");}

                        /* c. MENU USER READ (E-Book User)
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuUser == "3") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 12) / 2) << "E-Book Anda" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            
                            bukuUser = false;
                            for(int i = 0; i < jumlahEbookUser; i++) {
                                if(ebookUser[i].username == jawabNama){
                                    bukuUser = true;
                                    break;}}

                            if (bukuUser) {
                                cout << "JUDUL                    | PENULIS          | GENRE    " << endl;
                                cout << "-------------------------+------------------+------------" << endl;
                                for(int i = 0; i < jumlahEbookUser; i++){
                                    if(ebookUser[i].username == jawabNama){
                                        cout << left
                                            << setw(25) << ebookUser[i].buku.judul << "| "<< setw(17) << ebookUser[i].buku.penulis << "| "
                                            << setw(10) << ebookUser[i].buku.genre << endl;
                                        cout << right;}}}
                            else {
                                cout << "" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << setw((70 + 28) / 2) << "Anda Belum Memiliki E-Book." << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << "" << endl;}
                            cout << "" << endl;
                            system("pause");}

                        /* d. MENU USER UPDATE (Topup Saldo)
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuUser == "4") {
                            system("cls");
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
                            cout << "══════════════════════════════════════════════════════════════════════" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << setw((70 + 18) / 2) << "Topup Saldo Anda" << endl;
                            cout << "     ══════════════════════════════════════════════════════════     " << endl;
                            cout << "" << endl;
                            cout << "\n     Masukkan nominal topup: "; cin >> nominal;

                            if (nominal < 0) {
                                cout << "" << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                                cout << setw((70 + 28) / 2) << "Nominal tidak boleh minus!" << endl;
                                cout << setw((70 + 34) / 2) << "---------------------------------" << endl; 
                                cout << "" << endl;}
                            else {
                                akun[indeksLogin].saldo += nominal;
                                cout << "" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << setw((70 + 16) / 2) << "Topup berhasil!" << endl;
                                cout << setw((70 + 22) / 2) << "=====================" << endl;
                                cout << "" << endl;}
                            system("pause");}

                        /* e. MENU USER LOGOUT
                        ════════════════════════════════════════════════════*/
                        else if (pilihMenuUser == "5") {
                            cout << "" << endl;
                            cout << setw((70 + 22) / 2) << "=====================" << endl;
                            cout << setw((70 + 18) / 2) << "Logout berhasil!" << endl;
                            cout << setw((70 + 22) / 2) << "=====================" << endl;
                            cout << "" << endl;
                            system("pause");
                            break;}

                        /* f. SALAH INPUT MENU ADMIN
                        ════════════════════════════════════════════════════*/
                        else {
                            cout << "" << endl;
                            cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                            cout << setw((70 + 30) / 2) << "Pilihan menu tidak tersedia!" << endl;
                            cout << setw((70 + 34) / 2) << "---------------------------------" << endl; 
                            cout << "" << endl;  
                            system("pause");}}}}

            else {
                cout << "" << endl;
                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                cout << setw((70 + 56) / 2) << "Username atau Password salah atau akun belum terdaftar!" << endl;
                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;    
                salah++;
                cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                cout << setw((70 + 24) / 2) << "Kesempatan anda tersisa " << 3 - salah << endl;
                cout << setw((70 + 34) / 2) << "---------------------------------" << endl; 
                cout << "" << endl;

                if (salah == 3) {
                    cout << setw((70 + 40) / 2) << "=======================================" << endl;
                    cout << setw((70 + 52) / 2) << "Anda telah salah 3 kali. Silakan datang lain kali." << endl;
                    cout << setw((70 + 40) / 2) << "=======================================" << endl;
                    break;}
                system("pause");}
        }

        /* 2. REGISTRASI
        ════════════════════════════════════════════════════*/
        else if (pilihMenu == "2") {
            system("cls");
            cout << "══════════════════════════════════════════════════════════════════════" << endl;
            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
            cout << "══════════════════════════════════════════════════════════════════════" << endl;
            cout << "     ══════════════════════════════════════════════════════════     " << endl;
            cout << setw((70 + 22) / 2) << "Registrasi Akun Anda" << endl;
            cout << "     ══════════════════════════════════════════════════════════     " << endl;
            cout << "\n     Username: "; cin >> jawabNama;
            cout << "     Password: "; cin >> jawabPassword;

            userAda = false;
            for (int i = 0; i < jumlahUser; i++) {
                if (akun[i].username == jawabNama) {
                    userAda = true;
                    cout << "" << endl;
                    cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                    cout << setw((70 + 26) / 2) << "Username sudah terdaftar!" << endl;
                    cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
                    cout << "" << endl;
                    break;}}
            if (!userAda) {
                akun[jumlahUser].username = jawabNama;
                akun[jumlahUser].password = jawabPassword;
                akun[jumlahUser].role = "user";
                jumlahUser++;
                cout << "" << endl;
                cout << setw((70 + 40) / 2) << "=========================================" << endl;
                cout << setw((70 + 36) / 2) << "Registrasi berhasil! Silakan login." << endl;
                cout << setw((70 + 40) / 2) << "=========================================" << endl;
                cout << "" << endl;}
            system("pause");}


        /* 3. KELUAR PROGRAM
        ════════════════════════════════════════════════════*/
        else if (pilihMenu == "3") {
            system("cls");
            cout << "══════════════════════════════════════════════════════════════════════" << endl;
            cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
            cout << "══════════════════════════════════════════════════════════════════════" << endl;
            cout << "     ══════════════════════════════════════════════════════════     " << endl;
            cout << setw((70 + 36) / 2) << "Terima Kasih Telah Mengunjungi Kami" << endl;
            cout << "     ══════════════════════════════════════════════════════════     " << endl;
            cout << "" << endl;
            break;}
            

        /* 4. SALAH INPUT MENU AWAL
        ════════════════════════════════════════════════════*/
        else{
            cout << "" << endl;
            cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
            cout << setw((70 + 30) / 2) << "Pilihan menu tidak tersedia!" << endl;
            cout << setw((70 + 34) / 2) << "---------------------------------" << endl; 
            cout << "" << endl;  
            system("pause");}
    }

    return 0;
}