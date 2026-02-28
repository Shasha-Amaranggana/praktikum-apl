#include <iostream>
using namespace std;

int main() {
    int salah = 0;
    string jawabNama;
    string jawabPassword;
    string jawabMenu;
    float menit;
    float detik;
    float jam;
    string jawabLagi;

    cout << "\n\n===================================================" << endl;
    cout << "              WEBSITE KONVERSI WAKTU" << endl;
    cout << "===================================================" << endl;
    cout << "      =======================================" << endl;
    cout << "           Silakan login terlebih dahulu" << endl;
    cout << "      =======================================" << endl;

    do {
        cout << "\nUsername: ";
        cin >> jawabNama;
        cout << "Password: ";
        cin >> jawabPassword;

        if (jawabNama == "Shasha" && jawabPassword == "063") {
            break;
        }
        else if (jawabNama != "Shasha" && jawabPassword != "063") {
            cout << "\nUsername dan Password anda salah!" << endl;
            salah++;
        }
        else if (jawabPassword != "063") {
            cout << "\nPassword anda salah!" << endl;
            salah++;
        }
        else {
            cout << "\nUsername anda salah!" << endl;
            salah++;
        }
        cout << "Kesempatan anda tersisa " << 3 - salah << " kali." << endl;
    } while (salah < 3);
    
    if (salah == 3) {
        cout << "\n\n      =======================================" << endl;
        cout << "    Percobaan anda telah habis! YAHAHAH KASIAN.";
        cout << "\n      =======================================" << endl;
        return 0;
    }
    cout << "             ________________________" << endl;
    cout << "               Login anda berhasil!" << endl;
    cout << "             ________________________" << endl;

    while (true) {
        cout << "\n\n===================================================" << endl;
        cout << "              WEBSITE KONVERSI WAKTU" << endl;
        cout << "===================================================" << endl;
        cout << "      =======================================" << endl;
        cout << "            Selamat menjelajah, " << jawabNama << endl;
        cout << "      =======================================" << endl;

        cout << "\n1. Konversi Jam ke Menit dan Detik.";
        cout << "\n2. Konversi Menit ke Jam dan Detik.";
        cout << "\n3. Konversi Detik ke Jam dan Menit.";
        cout << "\n4. Keluar.";
        cout << "\n\nSilakan anda ingin melakukan apa? (input angka): ";
        cin >> jawabMenu;

        if (jawabMenu == "1") {
            do {
                cout << "\n\n      =======================================" << endl;
                cout << "          Konversi Jam ke Menit dan Detik" << endl;
                cout << "      =======================================" << endl;
                cout << "\nMasukkan nilai Jam yang ingin dikonversikan (angka): ";
                cin >> jam;
                menit = jam * 60;
                detik = jam * 3600;
                cout << jam << " jam = " << menit << " menit atau " << detik << " detik." << endl;

                cout << "\nApakah ingin melakukan konversi Jam lagi? (y/lainnya): ";
                cin >> jawabLagi;
            } while (jawabLagi == "y" || jawabLagi == "Y");
        }

        else if (jawabMenu == "2") {
            do {
                cout << "\n\n      =======================================" << endl;
                cout << "          Konversi Menit ke Jam dan Detik" << endl;
                cout << "      =======================================" << endl;
                cout << "\nMasukkan nilai Menit yang ingin dikonversikan (angka): ";
                cin >> menit;
                jam = menit / 60;
                detik = menit * 60;
                cout << menit << " menit = " << jam << " jam atau " << detik << " detik." << endl;
            
                cout << "\nApakah ingin melakukan konversi Menit lagi? (y/lainnya)";
                cin >> jawabLagi;
            } while (jawabLagi == "y" || jawabLagi == "Y");
        }

        else if (jawabMenu == "3") {
            do {
                cout << "\n\n      =======================================" << endl;
                cout << "          Konversi Detik ke Jam dan Menit" << endl;
                cout << "      =======================================" << endl;
                cout << "\nMasukkan nilai Detik yang ingin dikonversikan (angka): ";
                cin >> detik;
                jam = detik / 3600;
                menit = detik / 60;
                cout << detik << " detik = " << jam << " jam atau " << menit << " menit." << endl;

                cout << "\nApakah ingin melakukan konversi Detik lagi? (y/lainnya)" << endl;
                cin >> jawabLagi;
            } while (jawabLagi == "y" || jawabLagi == "Y");
        }

        else if (jawabMenu == "4") {
            cout << "\n\n      =======================================" << endl;
            cout << "                Terima kasih, " << jawabNama << endl;
            cout << "      =======================================" << endl;
            break;

        }
        else {
            cout << "             ________________________" << endl;
            cout << "    Pilihan anda tidak tersedia. Isi yang bener!" << endl;
            cout << "             ________________________" << endl;
        }
    }

    return 0;
}