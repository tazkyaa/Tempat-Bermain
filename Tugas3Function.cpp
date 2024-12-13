#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

// Fungsi Pembagian (Menggunakan Pass by Value)
double pembagian(double a, double b) {
    if (b == 0) {
        cout << "Pembagi tidak boleh nol. Mohon menginputkan kembali bilangan." << endl;
        return 0;
    }
    return a / b;
}

// Fungsi Perkalian (Menggunakan Pass by References)
void perkalian(double &hasil, double a, double b) {
    hasil = a * b;
}

// Fungsi Pengurangan (Menggunakan Pass by Address)
void pengurangan(double *hasil, double a, double b) {
    *hasil = a - b;
}

// Fungsi Penjumlahan
double penjumlahan(double a, double b) {
    return a + b;
}

// Fungsi Konversi +/-
double konversiTanda(double a) {
    return -a;
}

// Fungsi Konversi Persen
double konversiPersen(double a, double b) {
    return a * (b / 100);
}

// Fungsi Login
bool login(const string& username, const string& password) {
    string inputUser, inputPass;
    int tempt = 3;

    cout << setw(25) << setfill('=') << '=' << endl;
    cout << "|\tLOGIN AKUN\t|\n";
    cout << setw(25) << setfill('=') << '=' << endl;

    while (tempt > 0) {
        cout << "Username: ";
        cin >> inputUser;
        cout << "Password: ";
        inputPass = "";
        char ch;
        while ((ch = getch()) != '\r') { // Untuk menginputkan tanpa terlihat di layar user. Dan, While Loop akan terus berjalan apabila user belum menekan Enter.
            inputPass.push_back(ch); // 'Push Back' untuk memasukkan inputan user (ch) ke dalam 'pass'
            cout << '*'; // Dan lalu akan dicoutkan dengan bentuk '*'.
        }
        cout << endl;

        if (inputUser == username && inputPass == password) {
            cout << "Login Successful." << endl;
            system("pause");
            system("cls");
            return true;
        } else {
            tempt--;
            cout << "\nUnsuccessful Login. Kesempatan login tersisa: " << tempt << endl;
        }
    }
    return false; // Program akan berhenti apabila tempt (kesempatan) telah habis.
}

// Fungsi Menu
int menu(double hasil, const string& riwayat) {
    int pilih;
    system("cls");
    cout << setw(35) << setfill('=') << '=' << endl; // Penggunaan 'setw' & 'setfill' dimana,
    cout << "|\tKALKULATOR SEDERHANA\t  |\n";        // 'setw' sebagai luas bidang & 'setfill' sebagai isian dalam luas bidang tsb.
    cout << setw(35) << setfill('=') << '=' << endl;

    cout << "Riwayat (Ans) : " << hasil << " " << riwayat << endl;

    cout << "Menu:\n";
    cout << "1) Pembagian\n";
    cout << "2) Perkalian\n";
    cout << "3) Pengurangan\n";
    cout << "4) Penjumlahan\n";
    cout << "5) Konversi +/-\n";
    cout << "6) Konversi %\n";    
    cout << "0) Keluar\n";
    cout << setw(35) << setfill('=') << '=' << endl;
    cout << "Pilih\t: ";
    cin >> pilih;
    return pilih;
}

int main() {
    string username = "kya"; // Ketentuan Usernam & Password.
    string password = "029";

    if (!login(username, password)) {
        cout << "Kesempatan anda telah habis. Anda diblokir." << endl;
        return 0;
    }

    string backtomenu;
    double bil1, bil2, hasil = 0;
    string riwayat;

    do {
        system("cls");
        int pilih = menu(static_cast<int>(hasil), riwayat); // 'static_cast<int>' digunakan untuk menghilangkan desimal.

        switch (pilih) {
            case 1:
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "|\t1. Pembagian\t\t|\n";
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "Inputkan 2 bilangan:\n";
                cout << "Bil. 1 : ";
                cin >> bil1;
                cout << "Bil. 2 : ";
                cin >> bil2;
                hasil = pembagian(bil1, bil2); // Menggunakan Pass by Value.
                riwayat = "(" + to_string(static_cast<int>(bil1)) + " / " + to_string(static_cast<int>(bil2)) + ")";
                cout << "Hasil Pembagian : " << hasil << endl;
                break;

            case 2:
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "|\t2. Perkalian\t\t|\n";
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "Inputkan 2 bilangan:\n";
                cout << "Bil. 1 : ";
                cin >> bil1;
                cout << "Bil. 2 : ";
                cin >> bil2;
                perkalian(hasil, bil1, bil2); // Menggunakan Pass by References.
                riwayat = "(" + to_string(static_cast<int>(bil1)) + " * " + to_string(static_cast<int>(bil2)) + ")";
                cout << "Hasil Perkalian : " << hasil << endl;
                break;

            case 3:
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "|\t3. Pengurangan\t\t|\n";
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "Inputkan 2 bilangan:\n";
                cout << "Bil. 1 : ";
                cin >> bil1;
                cout << "Bil. 2 : ";
                cin >> bil2;
                pengurangan(&hasil, bil1, bil2); // Menggunakan Pass by Address.
                riwayat = "(" + to_string(static_cast<int>(bil1)) + " - " + to_string(static_cast<int>(bil2)) + ")";
                cout << "Hasil Pengurangan : " << hasil << endl;
                break;

            case 4:
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "|\t4. Penjumlahan\t\t|\n";
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "Inputkan 2 bilangan:\n";
                cout << "Bil. 1 : ";
                cin >> bil1;
                cout << "Bil. 2 : ";
                cin >> bil2;
                hasil = penjumlahan(bil1, bil2);
                riwayat = "(" + to_string(static_cast<int>(bil1)) + " + " + to_string(static_cast<int>(bil2)) + ")";
                cout << "Hasil Penjumlahan : " << hasil << endl;
                break;

            case 5:
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "|\t5. Konversi +/-\t\t|\n";
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "Inputkan sebuah bilangan:\n";
                cout << "Bilangan : ";
                cin >> bil1;
                hasil = konversiTanda(bil1);
                riwayat = "(" + to_string(static_cast<int>(bil1)) + " -> - " + to_string(static_cast<int>(bil1)) + ")";
                cout << "Hasil Konversi +/- : " << hasil << endl;
                break;

            case 6:
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "|\t6. Konversi %\t\t|\n";
                cout << setw(33) << setfill('=') << '=' << endl;
                cout << "Inputkan sebuah bilangan:\n";
                cout << "Bilangan : ";
                cin >> bil1;
                cout << "Inputkan persen (tanpa simbol %) : ";
                cin >> bil2;
                hasil = konversiPersen(bil1, bil2);
                riwayat = "(" + to_string(static_cast<int>(bil1)) + " * " + to_string(static_cast<int>(bil2)) + "%)";
                cout << "Hasil Konversi % : " << hasil << endl;
                break;

            case 0:
                cout << setw(50) << setfill('=') << '=' << endl;
                cout << "|\t Thanks for using this Calculator!\t |\n";
                cout << setw(50) << setfill('=') << '=' << endl;
                return 0;

            default:
                cout << "anda pencet apa cik? :<\n"; // Error handling untuk user yang memilih pilihan diluar yang sudah tertera (0-6).
                break;
        }
        cout << "Kembali ke menu? (y/n) : ";
        cin >> backtomenu;
    } while (backtomenu == "Y" || backtomenu == "y");

    return 0;
}
