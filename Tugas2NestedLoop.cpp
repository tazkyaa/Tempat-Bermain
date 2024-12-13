#include <iostream>
using namespace std;

void persegi(int sisi) {
    for (int i = 1; i <= sisi; ++i) {
        for (int j = 1; j <= sisi; ++j) {
            cout << " +";
        }
        cout << endl;
    }
}

void persegiBerongga(int sisi) {
    for (int i = 1; i <= sisi; ++i) {
        for (int j = 1; j <= sisi; ++j) {
            if (i == 1 || i == sisi || j == 1 || j == sisi) {
                cout << " +";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void segitigaSS(int sisi) {
    for (int i = 1; i <= sisi; ++i) {
        for (int j = 0; j < sisi - i; ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i; ++j) {
            cout << "+ ";
        }
        cout << endl;
    }
}

void segitigaSK(int sisi) {
    for (int i = 1; i <= sisi; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << "+ ";
        }
        cout << endl;
    }
}

void segitigaSamaKaki(int sisi) {
    for (int i = 1; i <= sisi; ++i) {
        for (int j = i; j < sisi; ++j) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "+";
        }
        cout << endl;
    }
}

void belahKetupat(int sisi) {
    for (int i = 1; i <= sisi; ++i) { // Untuk bagian atas.
        for (int j = i; j < sisi; ++j) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "+";
        }
        cout << endl;
    }

    for (int i = sisi - 1; i >= 1; --i) { // Untuk bagian bawah.
        for (int j = sisi; j > i; --j) {
            cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); ++k) {
            cout << "+";
        }
        cout << endl;
    }
}

int main() {
    int pilihan, ukuran;
    string backtomenu;

    do {
        system("cls");
        cout << "List bangun datar:\n";
        cout << "1) Persegi\n";
        cout << "2) Persegi berongga\n";
        cout << "3) Segitiga sama sisi\n";
        cout << "4) Segitiga siku-siku\n";
        cout << "5) Segitiga sama kaki\n";
        cout << "6) Belah ketupat\n";
        cout << "7) Keluar\n";
        cout << "Masukkan pilihan (1/2/3/4/5/6/7): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan panjang ukuran (sisi/tinggi): ";
                cin >> ukuran;
                persegi(ukuran);
                break;
            case 2:
                cout << "Masukkan panjang ukuran (sisi/tinggi): ";
                cin >> ukuran;
                persegiBerongga(ukuran);
                break;
            case 3:
                cout << "Masukkan panjang ukuran (sisi/tinggi): ";
                cin >> ukuran;
                segitigaSS(ukuran);
                break;
            case 4:
                cout << "Masukkan panjang ukuran (sisi/tinggi): ";
                cin >> ukuran;
                segitigaSK(ukuran);
                break;
            case 5:
                cout << "Masukkan panjang ukuran (sisi/tinggi): ";
                cin >> ukuran;
                segitigaSamaKaki(ukuran);
                break;
            case 6:
                cout << "Masukkan panjang ukuran (sisi/tinggi): ";
                cin >> ukuran;
                belahKetupat(ukuran);
                break;
            case 7:
                cout << "Terima kasih! :D";
                return 0;
            default:
                cout << "salah ketik cik :<\n";
                break;
        }

        cout << "Apakah ingin mengulang kembali? (y/n): ";
        cin >> backtomenu;

    } while (backtomenu == "y" || backtomenu == "Y");

    return 0;
}
