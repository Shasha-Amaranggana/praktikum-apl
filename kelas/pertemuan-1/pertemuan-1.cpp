// #include <iostream>
// using namespace std;
// int main() {
//     int arr[5][5];
//     // Mengisi array
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             arr[i][j] = i + j;
//         }
//     }
//     // Menampilkan array
//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 5; j++) {
//             cout << arr[i][j] << " ";
//         }

//         cout << endl;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;
// int main() {
//     int arr[3][3][3];
//     // Mengisi array 3D dengan pola berbeda
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             for (int k = 0; k < 3; k++) {
//                 arr[i][j][k] = (i + 1) * (j + k + 1);
//             }
//         }
//     }
//     // Menampilkan isi array 3D
//     for (int i = 0; i < 3; i++) {
//         cout << "Layer ke-" << i << endl;
//         for (int j = 0; j < 3; j++) {
//             for (int k = 0; k < 3; k++) {
//                 cout << arr[i][j][k] << " ";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }
//     return 0;
// }


// #include <iostream>
// using namespace std;
// int main() {
//     int angka = 50;
//     int *pAngka;
//     // Pointer menyimpan alamat variabel angka
//     pAngka = &angka;
//     // Menampilkan nilai dan alamat
//     cout << "Nilai variabel angka : " << angka << endl;
//     cout << "Alamat variabel angka : " << &angka << endl;
//     cout << "Alamat yang disimpan pointer : " << pAngka << endl;
//     cout << "Nilai yang diakses melalui pointer : " << *pAngka << endl;
//     return 0;
// }


#include <iostream>
using namespace std;
int main() {
    int data[5] = {10, 20, 30, 40, 50};
    int *p = data; // Pointer menunjuk ke elemen pertama array
    // Pointer bergerak selama masih berada dalam batas array
    while (p < data + 5) {
        cout << "Nilai: " << *p << ", Alamat: " << p << endl;
        p++; // Maju ke elemen berikutnya
    }
    return 0;
}