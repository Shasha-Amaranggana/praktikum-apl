#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
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
    int harga;};

struct EbookUser {
    string username;
    Ebook buku;};


/* PROSEDUR DAN FUNGSI
════════════════════════════════════════════════════*/
void judul_subjudul(string subjudul) {
    int spasiKiri = (70 - subjudul.length()) / 2;
    cout << "══════════════════════════════════════════════════════════════════════" << endl;
    cout << "│                    ☕📓   E-BOOKIE STORE   📓☕                    │" << endl;
    cout << "══════════════════════════════════════════════════════════════════════" << endl;
    cout << "      ══════════════════════════════════════════════════════════      " << endl;
    cout << string(spasiKiri, ' ') << subjudul << endl;
    cout << "      ══════════════════════════════════════════════════════════      " << endl;}

void tampilPesan(int nilai, string pesan) {
    cout << "" << endl;
    cout << setw((70 + 26) / 2) << "=========================" << endl;
    cout << setw((70 + nilai) / 2) << pesan << endl;
    cout << setw((70 + 26) / 2) << "=========================" << endl;
    cout << "" << endl;}

void tampilPeringatan(int nilai, string pesan) {
    cout << "" << endl;
    cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
    cout << setw((70 + nilai) / 2) << pesan << endl;
    cout << setw((70 + 34) / 2) << "---------------------------------" << endl;
    cout << "" << endl;}

int scrollMenu(int pilih, int jumlahMenu) {
    int tombol = getch();

    if (tombol == 224 || tombol == 0) {
        tombol = getch();
        if (tombol == 72) {
            pilih = (pilih - 1 + jumlahMenu) % jumlahMenu;}
        else if (tombol == 80) {
            pilih = (pilih + 1) % jumlahMenu;}}
    else if (tombol == 13) {
        return -1;}

    return pilih;} 

int scrollBuku(Ebook katalog[], int jumlahBuku, string judulMenu) {
    int pilih = 0;

    while(true){
        system("cls");
        judul_subjudul(judulMenu);
        cout << "" << endl;
        for(int i = 0; i < jumlahBuku; i++){
            if(i == pilih)
                cout << "> " << katalog[i].judul << endl;
            else
                cout << "  " << katalog[i].judul << endl;}
        int hasil = scrollMenu(pilih, jumlahBuku);
        if(hasil == -1)
            return pilih;

        pilih = hasil;}}   


void readKatalog(Ebook katalog[], int jumlahBuku, int indeks = 0) {
    if (jumlahBuku == 0) {
        tampilPesan(28, "Katalog E-book belum terisi.");
        return;}
    if (indeks == 0) {
        cout << "ID | JUDUL                    | PENULIS             | TAHUN   | GENRE     | HARGA" << endl;
        cout << "---+--------------------------+---------------------+---------+-----------+--------" << endl;}
    if (indeks >= jumlahBuku) {
        cout << right << endl;
        return;}
    cout << left
        << setw(3) << katalog[indeks].id << "| "<< setw(25) << katalog[indeks].judul << "| "
        << setw(20) << katalog[indeks].penulis << "| " << setw(8) << katalog[indeks].tahun << "| "
        << setw(10) << katalog[indeks].genre << "| " << setw(10) << katalog[indeks].harga
        << endl;
    readKatalog(katalog, jumlahBuku, indeks + 1);}

int createEbook(Ebook katalog[], int jumlahBuku) {
    int IdBuku, TahunBuku, HargaBuku;
    string JudulBuku, PenulisBuku, GenreBuku;
    bool bukuAda = false;

    cout << "\n     ID: "; cin >> IdBuku;
    cin.ignore();
    cout << "     Judul: "; getline(cin, JudulBuku);
    cout << "     Penulis: "; getline(cin, PenulisBuku);
    cout << "     Tahun: "; cin >> TahunBuku;
    cout << "     Genre: "; cin >> GenreBuku;
    cout << "     Harga: "; cin >> HargaBuku;
    for (int i = 0; i < jumlahBuku; i++) {
        if (katalog[i].id == IdBuku) {
            bukuAda = true;
            tampilPeringatan(26, "ID E-book telah tersedia!");
            break;}}
    if (!bukuAda) {
        katalog[jumlahBuku].id = IdBuku;
        katalog[jumlahBuku].judul = JudulBuku;
        katalog[jumlahBuku].penulis = PenulisBuku;
        katalog[jumlahBuku].tahun = TahunBuku;
        katalog[jumlahBuku].genre = GenreBuku;
        katalog[jumlahBuku].harga = HargaBuku;
        jumlahBuku++;
        tampilPesan(30, "E-book berhasil ditambahkan!");}
    
    return jumlahBuku;}

void updateHarga(Ebook katalog[], int jumlahBuku) {
    int hargaBaru;

    cout << "    Pilih E-book yang ingin diubah harganya: " << endl;
    cout << "" << endl;
    int pilihan = scrollBuku(katalog, jumlahBuku, "Ubah Harga E-Book");
    cout << "";
    cout << "\n     Judul E-Book : " << katalog[pilihan].judul << endl;
    cout << "     Harga lama : " << katalog[pilihan].harga << endl;
    cout << "";
    cout << "\n     Masukkan harga baru: "; cin >> hargaBaru;
    katalog[pilihan].harga = hargaBaru;
    tampilPesan(34, "Harga E-book berhasil diperbarui!");}

int deleteEbook(Ebook katalog[], int jumlahBuku) {
    cout << "    Pilih E-book yang ingin dihapus: " << endl;
    cout << "" << endl;
    int pilihan = scrollBuku(katalog, jumlahBuku, "Hapus E-Book");
    cout << "" << endl;
    cout << "\n     ID  : " << katalog[pilihan].id << endl;
    cout << "     Judul E-Book : " << katalog[pilihan].judul << endl;
    cout << "" << endl;
    for (int j = pilihan; j < jumlahBuku - 1; j++) {
        katalog[j] = katalog[j + 1];}
    jumlahBuku--;
    tampilPesan(26, "E-book berhasil dihapus!");

    return jumlahBuku;}


int createPesan(Ebook katalog[], int jumlahBuku, EbookUser ebookUser[], int jumlahEbookUser, Akun akun[], int indeksLogin, string jawabNama) {
    bool sudahBeli = false;

    cout << "    Pilih E-book yang ingin dipesan: " << endl;
    cout << "" << endl;
    int pilihan = scrollBuku(katalog, jumlahBuku, "Pesan E-Book");

    for (int i = 0; i < jumlahBuku; i++) {
        for(int j = 0; j < jumlahEbookUser; j++){
            if(ebookUser[j].username == jawabNama && ebookUser[j].buku.id == pilihan){
                sudahBeli = true;
                break;}}}

    if (sudahBeli) {
        tampilPeringatan(32, "Anda sudah membeli E-book ini!");}
    else {
        if (akun[indeksLogin].saldo >= katalog[pilihan].harga) {
            akun[indeksLogin].saldo -= katalog[pilihan].harga;
            akun[0].saldo += katalog[pilihan].harga;
            ebookUser[jumlahEbookUser].username = jawabNama;
            ebookUser[jumlahEbookUser].buku = katalog[pilihan];

            jumlahEbookUser++;
            cout << "" << endl;
            cout << "\n     ID  : " << katalog[pilihan].id << endl;
            cout << "     Judul E-Book : " << katalog[pilihan].judul << endl;
            cout << "" << endl;
            cout << "" << endl;
            tampilPesan(24, "E-book berhasil dibeli!");
            cout << "" << endl;}
        else {
            tampilPeringatan(24, "Saldo anda tidak cukup!");}}
    return jumlahEbookUser;}

void readEbookUser(EbookUser ebookUser[], int jumlahEbookUser, string jawabNama) {
    bool bukuUser = false;

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
        tampilPesan(28, "Anda belum memiliki E-book.");}
    cout << "" << endl;}

void updateSaldo(Akun akun[], int indeksLogin) {
    int nominal;
    cout << "\n     Masukkan nominal topup: "; cin >> nominal;
    if (nominal <= 0) {
        tampilPeringatan(44, "Nominal tidak boleh minus atau bernilai 0!");}
    else {
        akun[indeksLogin].saldo += nominal;
        tampilPesan(16, "Topup berhasil!");}}


int login(Akun akun[], int jumlahUser) {
    string jawabNama, jawabPassword;

    cout << "\n     Username: "; cin >> jawabNama;
    cout << "     Password: "; cin >> jawabPassword;
    for (int i = 0; i < jumlahUser; i++) {
        if (akun[i].username == jawabNama && akun[i].password == jawabPassword) {
            tampilPesan(38, "Login berhasil! Selamat datang, " + jawabNama);
            system("pause");
            return i;}}
    return -1;}

int registrasi(Akun akun[], int jumlahUser) {
    string jawabNama, jawabPassword;
    bool userAda = false;

    cout << "\n     Username: "; cin >> jawabNama;
    cout << "     Password: "; cin >> jawabPassword;

    for (int i = 0; i < jumlahUser; i++) {
        if (akun[i].username == jawabNama) {
            userAda = true;
            tampilPeringatan(26, "Username sudah terdaftar!");
            break;}}
    if (!userAda) {
        akun[jumlahUser].username = jawabNama;
        akun[jumlahUser].password = jawabPassword;
        akun[jumlahUser].role = "user";
        jumlahUser++;
        tampilPesan(36, "Registrasi berhasil! Silakan login.");}
    return jumlahUser;}

int menuAdmin(Akun akun[], int indeksLogin, Ebook katalog[], int jumlahBuku) {
    string pilihMenuAdmin[] = {
        "   1 | Menu Katalog E-Book",
        "   2 | Tambahkan E-Book Baru",
        "   3 | Ubah Harga E-Book",
        "   4 | Hapus E-Book",
        "   5 | Logout"};
    int pilih = 0;
    
    while (true) {
        system("cls");
        judul_subjudul("Halo, Admin " + akun[indeksLogin].username);
        cout << setw((70 + 22) / 2) << "=====================" << endl;
        cout << setw((70 + 2) / 2) << "Saldo: " << akun[indeksLogin].saldo << endl;
        cout << setw((70 + 22) / 2) << "=====================" << endl;
        cout << "" << endl;
        for (int i = 0; i < 5; i++) {
            if (i == pilih)
                cout << "> " << pilihMenuAdmin[i] << endl;
            else
                cout << "  " << pilihMenuAdmin[i] << endl;}
        int hasil = scrollMenu(pilih, 5);
        if (hasil == -1) {
    
            /* a. MENU ADMIN READ (Katalog E-Book)
            ════════════════════════════════════════════════════*/
            if (pilih == 0) {
                system("cls");
                judul_subjudul("Menu Katalog E-Book");
                cout << "" << endl;
                readKatalog(katalog, jumlahBuku);
                system("pause");}

            /* b. MENU ADMIN CREATE (Tambah E-Book)
            ════════════════════════════════════════════════════*/
            else if (pilih == 1) {
                system("cls");
                judul_subjudul("Tambahkan E-Book Baru");
                cout << "" << endl;
                jumlahBuku = createEbook(katalog, jumlahBuku);
                system("pause");}

            /* c. MENU ADMIN UPDATE (Edit Harga E-Book)
            ════════════════════════════════════════════════════*/
            else if (pilih == 2) {
                system("cls");
                judul_subjudul("Ubah Harga E-Book");
                cout << "" << endl;
                updateHarga(katalog, jumlahBuku);
                system("pause");}

            /* d. MENU ADMIN DELETE (Hapus E-Book)
            ════════════════════════════════════════════════════*/
            else if (pilih == 3) {
                system("cls");
                judul_subjudul("Hapus E-Book");
                cout << "" << endl;
                jumlahBuku = deleteEbook(katalog, jumlahBuku);
                system("pause");}

            /* e. MENU ADMIN LOGOUT
            ════════════════════════════════════════════════════*/
            else {
                tampilPesan(18, "Logout berhasil!");
                system("pause");
                break;}}
        
        else {
            pilih = hasil;}}
        return jumlahBuku;}

int menuUser(Akun akun[], int indeksLogin, Ebook katalog[], int jumlahBuku, EbookUser ebookUser[], int jumlahEbookUser) {
    string pilihMenuUser[] = {
        "   1 | Menu Katalog E-Book",
        "   2 | Pesan E-Book",
        "   3 | E-Book Anda",
        "   4 | Topup Saldo",
        "   5 | Logout"};
    int pilih = 0;
    
    while (true) {
        system("cls");
        judul_subjudul("Halo, Pengguna " + akun[indeksLogin].username);
        cout << setw((70 + 22) / 2) << "=====================" << endl;
        cout << setw((70 + 2) / 2) << "Saldo: " << akun[indeksLogin].saldo << endl;
        cout << setw((70 + 22) / 2) << "=====================" << endl;
        cout << "" << endl;
        for (int i = 0; i < 5; i++) {
            if (i == pilih)
                cout << "> " << pilihMenuUser[i] << endl;
            else
                cout << "  " << pilihMenuUser[i] << endl;}
        int hasil = scrollMenu(pilih, 5);
        if (hasil == -1) {
    
            /* a. MENU USER READ (Katalog E-Book)
            ════════════════════════════════════════════════════*/
            if (pilih == 0) {
                system("cls");
                judul_subjudul("Menu Katalog E-Book");
                cout << "" << endl;
                readKatalog(katalog, jumlahBuku);
                system("pause");}

            /* b. MENU USER CREATE (Pesan E-Book)
            ════════════════════════════════════════════════════*/
            else if (pilih == 1) {
                system("cls");
                judul_subjudul("Pesan E-Book");
                cout << "" << endl;
                jumlahEbookUser = createPesan(katalog, jumlahBuku, ebookUser, jumlahEbookUser, akun, indeksLogin, akun[indeksLogin].username);
                system("pause");}

            /* c. MENU USER READ (E-Book User)
            ════════════════════════════════════════════════════*/
            else if (pilih == 2) {
                system("cls");
                judul_subjudul("E-Book Anda");
                cout << "" << endl;
                readEbookUser(ebookUser, jumlahEbookUser, akun[indeksLogin].username);
                system("pause");}

            /* d. MENU USER UPDATE (Topup Saldo)
            ════════════════════════════════════════════════════*/
            else if (pilih == 3) {
                system("cls");
                judul_subjudul("Topup Saldo Anda");
                cout << "" << endl;
                updateSaldo(akun, indeksLogin);
                system("pause");}

            /* e. MENU USER LOGOUT
            ════════════════════════════════════════════════════*/
            else {
                tampilPesan(18, "Logout berhasil!");
                system("pause");
                break;}}
            
        else {
            pilih = hasil;}}
        return jumlahEbookUser;}


/* MAIN
════════════════════════════════════════════════════*/
int main() {
    SetConsoleOutputCP(65001);

    string pilihMenu[] = {
        "   1 | Login", 
        "   2 | Register",
        "   3 | Keluar"}; 

    Akun akun[100] = {
        {"Shasha", "063", "admin", 0},
        {"Aura", "015", "user", 100000}};

    Ebook katalog[100] = {
        {1, "Magnus Chase 1", "Rick Riordan", 2015, "Fantasi", 70000},
        {2, "The Walled City", "Ryan Graudin", 2014, "Drama", 50000},
        {3, "City of Lost Souls", "Cassandra Clare", 2012, "Fantasi", 60000},
        {4, "The Trials of Apollo 2", "Rick Riordan", 2017, "Fantasi", 50000},
        {5, "The Trials of Apollo 3", "Rick Riordan", 2018, "Fantasi", 50000}};

    EbookUser ebookUser[100];
    
    int jumlahUser = 2;
    int jumlahBuku = 5;
    int jumlahEbookUser = 0;
    int salah = 0;
    int pilih = 0;
    
    /* PROGRAM UTAMA
    ════════════════════════════════════════════════════*/
    while (true) {
        system("cls");
        judul_subjudul("Selamat Datang");
        for (int i = 0; i < 3; i++) {
            if (i == pilih)
                cout << "> " << pilihMenu[i] << endl;
            else
                cout << "  " << pilihMenu[i] << endl;}

        int hasil = scrollMenu(pilih, 3);
        if (hasil == -1) {

            /* A. LOGIN
            ════════════════════════════════════════════════════*/
            if (pilih == 0) {
                system("cls");
                judul_subjudul("Login Akun Anda");
                int indeksLogin = login(akun, jumlahUser);
                if (indeksLogin != -1) {
                    salah = 0;

                    /* 1. MENU ADMIN (CRUD)
                    ════════════════════════════════════════════════════*/
                    if (akun[indeksLogin].role == "admin") {
                        jumlahBuku = menuAdmin(akun, indeksLogin, katalog, jumlahBuku);}

                    /* 2. MENU USER (CRUD)
                    ════════════════════════════════════════════════════*/
                    else {
                        jumlahEbookUser = menuUser(akun, indeksLogin, katalog, jumlahBuku, ebookUser, jumlahEbookUser);}
                }

                else {
                    tampilPeringatan(56, "Username atau Password salah atau akun belum terdaftar!");
                    salah++;
                    tampilPeringatan(26, "Kesempatan anda tersisa " + to_string(3 - salah));

                    if (salah == 3) {
                        tampilPesan(52, "Anda telah salah 3 kali. Silakan datang lain kali.");
                        break;}
                    system("pause");}
            }


            /* 2. REGISTRASI
            ════════════════════════════════════════════════════*/
            else if (pilih == 1) {
                system("cls");
                judul_subjudul("Registrasi Akun Anda");
                jumlahUser = registrasi(akun, jumlahUser);
                system("pause");}


            /* 3. KELUAR PROGRAM
            ════════════════════════════════════════════════════*/
            else {
                system("cls");
                judul_subjudul("Terima Kasih Telah Mengunjungi Kami");
                cout << "" << endl;
                break;}
        }
        else {
            pilih = hasil;}
    }
    
    return 0;
}