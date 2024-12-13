#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string namaGame[100]; // Deklarasi Array.
int stokGame[100];
double hargaGame[100];
int jumlahGame = 0;

// Function Konfirmasi Data
void konfirGame(int jumlahInput) {
    cout << "\n[Data game yang baru saja ditambahkan.]\n";
    for (int i = jumlahGame - jumlahInput; i < jumlahGame; i++) {
        cout << endl
             << setw(16) << left << setfill('-') << '-'
             << "Game ke " << i + 1
             << setw(16) << right << setfill('-') << '-' << endl;
        cout << setw(40) << setfill('-') << '-' << endl;
        cout << "Nama Game\t : " << namaGame[i] << endl;
        cout << "Stok Game\t : " << stokGame[i] << endl;
        cout << "Harga Game\t : " << fixed << setprecision(2) << hargaGame[i] << endl;
    }
    cout << setw(40) << setfill('-') << '-' << endl;
    cout << "\n[Data Game berhasil ditambahkan.]\n";
}

// Function Input Data Game.
void inputDataGame() {
    int jumlahInput;
    cout << "Masukkan jumlah game yang ingin ditambahkan : ";
    cin >> jumlahInput;
    cin.ignore();
    cout << endl;
    cout << setw(35) << setfill('=') << '=' << endl;
    cout << "||\t  INPUT DATA GAME\t ||\n";
    cout << setw(35) << setfill('=') << '=' << endl;

    for (int i = 0; i < jumlahInput; i++) {
        cout << "\nData Game ke-" << i + 1 << endl;
        cout << "Nama Game\t : ";
        getline(cin, namaGame[jumlahGame]);
        cout << "Stok Game\t : ";
        cin >> stokGame[jumlahGame];
        cout << "Harga Game\t : ";
        cin >> hargaGame[jumlahGame];
        cin.ignore();

        char konfirmasi;
        cout << "Apakah data sudah benar? (y/n) : ";
        cin >> konfirmasi;
        cin.ignore();

        if (konfirmasi == 'y' || konfirmasi == 'Y') {
            jumlahGame++;
        } else {
            cout << "Data game dibatalkan, silahkan input ulang." << endl;
            i--;
        }
    }

    konfirGame(jumlahInput); // Tampilkan hanya data yang baru saja diinput.
}


// Function Lihat Data Game.
void lihatDataGame() {
    if (jumlahGame == 0) { // Error handling jika belum ada data game yang ditambahkan.
        cout << "\n[Belum ada data Game di stok.]\n";
        return;
    }
    cout << setfill(' '); 
    cout << "\n=============================================\n";
    cout << setw(5) << left << "No"
         << setw(20) << left << "Nama Game"
         << setw(10) << left << "Stok"
         << setw(15) << left << "Harga" << endl;
    cout << "=============================================\n";

    double totalHarga = 0;
    for (int i = 0; i < jumlahGame; i++) {
        cout << setw(5) << left << i + 1
             << setw(20) << left << namaGame[i]
             << setw(10) << left << stokGame[i]
             << setw(15) << left << fixed << setprecision(2) << hargaGame[i] << endl;
        totalHarga += hargaGame[i] * stokGame[i];
    }

    cout << "=============================================\n";
    cout << "Total harga semua Game : Rp " << fixed << setprecision(2) << totalHarga << endl;
}


// Function Menu.
void MenuAwal() {
    cout << setw(35) << setfill('=') << '=' << endl; // Penggunaan 'setw' & 'setfill' dimana,
    cout << "||\t HATA GAME CENTER\t ||\n";        // 'setw' sebagai luas bidang & 'setfill' sebagai isian dalam luas bidang tsb.
    cout << setw(35) << setfill('=') << '=' << endl;
    cout << "1. Input Data Game" << endl;
    cout << "2. Lihat Data Game" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih menu (1/2/3) : ";
}

int main() {
    int pilihan, i;
    char backtomenu;
    do { // Penggunaan Loop.
        system("cls");
        MenuAwal();
        cin >> pilihan;
        cin.ignore(); 

        switch (pilihan) {
            case 1:
                inputDataGame(); // Tempat penginputan game oleh user.
                break;
            case 2:
                lihatDataGame();
                break;
            case 3:
                cout << "Terima kasih telah berkunjung. Silahkan datang kembali^^";
                return 0;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl; // Error handling untuk user yang memilih pilihan diluar yang sudah tertera (1-3).
                break;
        }
        cout << "\nKembali ke menu utama? (y/n) : ";
        cin >> backtomenu;
    } while (backtomenu == 'Y' || backtomenu == 'y');
}
