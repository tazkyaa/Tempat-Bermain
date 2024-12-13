#include <bits/stdc++.h>
using namespace std;

const int maks = 5;
string user[maks][2]; 
int usersekarang = 0;

// struktur data tiket
struct Tiket
{
    string username;         // Username
    string kereta;           // Nama kereta
    string stasiunAsal;      // Stasiun keberangkatan
    string stasiunTujuan;    // Stasiun tujuan
    string kelas;            // Kelas tiket
    string jamKeberangkatan; // Jam keberangkatan
    int harga;               // Harga
};

Tiket tiket[maks];  // nyimpen data tiket
int tiketCount = 0; // jumlah yang udah dipesen

//TAZKYA
void registerUser()
{
    system("cls");
    if (usersekarang >= maks) // untuk mengecek apakah jumlah pengguna (yg tersimpan dalam variabel usersekarang) 
                              // telah mencapai atau melebihi batas maks yang sudah ditentukan
    {
        cout << "Maaf, sudah mencapai batas pembuatan akun.\n";
        cout << "Silahkan Login dengan akun yang anda miliki.\n";
        system("pause"); // memberhentikan sebentar agar user dapat membaca pesan
        return; // kembali ke menu utama yg ada regist, login, keluar
    }

    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << setfill(' '); // menggunakan setw (lebar kolom) dan setfill (pengisian karakter untuk spasi kosong).
    cout << "|" << setw(50) << "REGISTER" << setw(51) << "|" << endl;
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;

    string username, password; // kita mendeklarasikan variable input

    // Loop untuk memastikan username yang dimasukkan tidak duplikat
    while (true)
    {
        bool isDuplicate = false; // Flag untuk memeriksa apakah usn sudah terdaftar sebelumnya
        cout << "Masukkan username: ";
        getline(cin >> ws, username); 

        // Periksa apakah username sudah terdaftar
        for (int i = 0; i < usersekarang; i++)
        {
            if (user[i][0] == username)
            {
                isDuplicate = true;
                cout << "Maaf, username sudah terdaftar. Coba username lain.\n";
                break; // Keluar dari loop for
            }
        }

        // Jika tidak ada duplikasi, keluar dari loop while
        if (!isDuplicate)
            break;
    }

    cout << "Masukkan password: ";
    cin >> password;

    user[usersekarang][0] = username; // Menyimpan username ke dalam array user pada indeks saat ini (usersekarang).
    user[usersekarang][1] = password; // Menyimpan password ke dalam array user pada indeks yang sama.
    usersekarang++; // enambahkan jumlah pengguna yang telah terdaftar.


    cout << "Registrasi berhasil!\n";
    system("pause");
}

bool loginUser(string &currentUser)
// bool: Fungsi ini mengembalikan nilai true jika login berhasil, dan false jika gagal.
// string &currentUser: Parameter referensi string yang akan menyimpan username pengguna yang berhasil login
// (akan mengubah nilai currentUser secara langsung. 
{
    system("cls");
    int batas = 3;
    while (batas > 0)
    {
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "LOGIN" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;

        string username, password;
        cout << "Masukkan username: ";
        getline(cin >> ws, username);
        cout << "Masukkan password: ";
        cin >> password;

        for (int i = 0; i < usersekarang; i++) // untuk mengecek seluruh data pengguna yang telah terdaftar
        {
            if (user[i][0] == username && user[i][1] == password) // Memeriksa apakah username dan password 
                                                                // yang dimasukkan cocok dengan data pengguna pada indeks ke-i.
            {
                cout << "[Login Successful.]\n";
                currentUser = username; // menyimpan username ke variabel currentuser
                system("pause");
                cout << setfill(' ');
                system("cls");
                return true;
            }
        }
        batas--;
        if (batas > 0)
        {
            cout << "Username atau password salah. Kesempatan login tersisa: " << batas << "\n";
        }
        else // sama sj dg batas == 0 (0==0) maka akan berhenti programnya
        {
            cout << "[Unsuccessful Login. You are blocked.]\n";
            exit(0);
        }
    }

    return false;
}

// Fungsi untuk memesan tiket
void pesantiket(const string &currentUser)
{
    // Validasi apakah user sudah memiliki tiket
    for (int i = 0; i < tiketCount; i++) {
        if (tiket[i].username == currentUser) {
            cout << "Anda sudah membeli tiket. Satu akun hanya bisa membeli satu tiket.\n";
            system("pause");
            cout << setfill(' ');
            return; // Kembali ke menu sebelumnya
        }
    }
    int stasiunber, stasiundat;

    // stasiun keberangkatan
    system("cls");
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(60) << "STASIUN KEBERANGKATAN" << setw(41) << "|" << endl;
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << "1. Yogyakarta (YK)\n";
    cout << "2. Lempuyangan (LPN)\n";
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << "Pilihan Anda: ";
    cin >> stasiunber;

    // 1. stasiun tujuan
    cout << "\n\n+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(60) << "STASIUN TUJUAN" << setw(41) << "|" << endl;
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << "1. Solo Balapan (SLO)\n";
    cout << "2. Yogyakarta International Airport (YIA)\n";
    cout << "3. Palur (PL)\n";
    cout << "4. Gambir (GMR)\n";
    cout << "5. Surabaya Gubeng (SGU)\n";
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << "Pilihan Anda: ";
    cin >> stasiundat;

    // 2. Data tiket sesuai rute yang dipilih
    // sesuaikan sama jumlah stasiun kedatangan sama keberangkatannya

    // daftar tiket mulai
    if (stasiunber == 1 && stasiundat == 1)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: Argo Lawu (Rp.350.000) 02:52\n";
        cout << "2. Kereta: Argo Dwipangga (Rp.350.000) 15:01\n";
        cout << "3. Kereta: Manahan Fakultatif (Rp.350.000) 17:39\n";
        cout << "4. Kereta : Lodaya (Rp.250.000) 14:00\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "Argo Lawu", "Yogyakarta (YK)", "Solo Balapan (SLO)", "Eksekutif", "02:52", 350000};
        }

        else if (pilihan == '2')
        {
            tiket[tiketCount++] = {currentUser, "Argo Dwipangga", "Yogyakarta (YK)", "Solo Balapan (SLO)", "Eksekutif", "15:01", 350000};
        }

        else if (pilihan == '3')
        {
            tiket[tiketCount++] = {currentUser, "Manahan Fakultatif", "Yogyakarta (YK)", "Solo Balapan (SLO)", "Eksekutif", "17:39", 350000};
        }

        else if (pilihan == '4')
        {
            tiket[tiketCount++] = {currentUser, "Lodaya", "Yogyakarta (YK)", "Solo Balapan (SLO)", "Campuran", "14:00", 250000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }

    else if (stasiunber == 1 && stasiundat == 2)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: Commuter Bandara YIA (Rp.50.000) 07:45\n";
        cout << "2. Kereta: Commuter Bandara YIA (Rp.50.000) 09:05\n";
        cout << "3. Kereta: Commuter Bandara YIA (Rp.50.000) 12:10\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "Commuter Bandara YIA", "Yogyakarta (YK)", "Yogyakarta International Airport (YIA)", "Ekonomi", "07:45", 50000};
        }

        else if (pilihan == '2')
        {
            tiket[tiketCount++] = {currentUser, "Commuter Bandara YIA", "Yogyakarta (YK)", "Yogyakarta International Airport (YIA)", "Ekonomi", "09:05", 50000};
        }

        else if (pilihan == '3')
        {
            tiket[tiketCount++] = {currentUser, "Commuter Bandara YIA", "Yogyakarta (YK)", "Yogyakarta International Airport (YIA)", "Ekonomi", "12:10", 50000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }

    else if (stasiunber == 1 && stasiundat == 3)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: COMMUTER LINE YOGYAKARTA (Rp.20.000) 06:50\n";
        cout << "2. Kereta: COMMUTER LINE YOGYAKARTA (Rp.20.000) 10:25\n";
        cout << "3. Kereta: COMMUTER LINE YOGYAKARTA (Rp.20.000) 13:45\n";
        cout << "4. Kereta : COMMUTER LINE YOGYAKARTA(Rp.20.000) 17:45\n";
        cout << "5. Kereta : COMMUTER LINE YOGYAKARTA(Rp.20.000) 07:35\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "COMMUTER LINE YOGYAKARTA", "Yogyakarta (YK)", "Palur (PL)", "Ekonomi", "06:50", 20000};
        }

        else if (pilihan == '2')
        {
            tiket[tiketCount++] = {currentUser, "ACOMMUTER LINE YOGYAKARTA", "Yogyakarta (YK)", "Palur (PL)", "Ekonomi", "10:25", 20000};
        }

        else if (pilihan == '3')
        {
            tiket[tiketCount++] = {currentUser, "COMMUTER LINE YOGYAKARTA", "Yogyakarta (YK)", "Palur (PL)", "Ekonomi", "13:45", 20000};
        }

        else if (pilihan == '4')
        {
            tiket[tiketCount++] = {currentUser, "COMMUTER LINE YOGYAKARTA", "Yogyakarta (YK)", "Palur (PL)", "Ekonomi", "17:45", 20000};
        }

        else if (pilihan == '5')
        {
            tiket[tiketCount++] = {currentUser, "COMMUTER LINE YOGYAKARTA", "Yogyakarta (YK)", "Palur (PL)", "Ekonomi", "07:35", 20000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }

    else if (stasiunber == 1 && stasiundat == 4)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: Argo Lawu (Rp.850.000) 02:52\n";
        cout << "2. Kereta: Argo Dwipangga (Rp.850.000) 15:01\n";
        cout << "3. Kereta: Manahan Fakultatif (Rp.750.000) 10:38\n";
        cout << "4. Kereta : Taksaka (Rp.850.000) 08:45\n";
        cout << "5. Kereta : Argo Semeru (Rp.850.000) 12:45\n";
        cout << "6. Kereta : Bima (Rp.850.000) 23:13\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "Argo Lawu", "Yogyakarta (YK)", "Gambir (GMR)", "Eksekutif", "02:52", 850000};
        }

        else if (pilihan == '2')
        {
            tiket[tiketCount++] = {currentUser, "Argo Dwipangga", "Yogyakarta (YK)", "Gambir (GMR)", "Eksekutif", "15:01", 850000};
        }

        else if (pilihan == '3')
        {
            tiket[tiketCount++] = {currentUser, "Manahan Fakultatif", "Yogyakarta (YK)", "Gambir (GMR)", "Eksekutif", "10:38", 750000};
        }

        else if (pilihan == '4')
        {
            tiket[tiketCount++] = {currentUser, "Taksaka", "Yogyakarta (YK)", "Gambir (GMR)", "Eksekutif", "08:45", 850000};
        }

        else if (pilihan == '5')
        {
            tiket[tiketCount++] = {currentUser, "Argo Semeru", "Yogyakarta (YK)", "Gambir (GMR)", "Eksekutif", "12:45", 850000};
        }

        else if (pilihan == '6')
        {
            tiket[tiketCount++] = {currentUser, "Bima", "Yogyakarta (YK)", "Gambir (GMR)", "Eksekutif", "23:13", 850000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }

    else if (stasiunber == 1 && stasiundat == 5)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: Sancaka (Rp.350.000) 06:45\n";
        cout << "2. Kereta: Sancaka (Rp.350.000) 11:30\n";
        cout << "3. Kereta: Argo Wilis (Rp.550.000) 13:38\n";
        cout << "4. Kereta : Argo Semeru (Rp.550.000) 12:59\n";
        cout << "5. Kereta : Bima (Rp.450.000) 23:33\n";
        cout << "6. Kereta : Turangga (Rp.450.000) 00:24\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "Sancaka", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Campuran", "06:45", 20000};
        }

        else if (pilihan == '2')
        {
            tiket[tiketCount++] = {currentUser, "Sancaka", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Campuran", "11:30", 20000};
        }

        else if (pilihan == '3')
        {
            tiket[tiketCount++] = {currentUser, "Argo Wilis", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Eksekutif", "13:38", 20000};
        }

        else if (pilihan == '4')
        {
            tiket[tiketCount++] = {currentUser, "Argo Semeru", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Eksekutif", "12:59", 20000};
        }

        else if (pilihan == '5')
        {
            tiket[tiketCount++] = {currentUser, "Bima", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Eksekutif", "23:33", 20000};
        }

        else if (pilihan == '6')
        {
            tiket[tiketCount++] = {currentUser, "Turangga", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Eksekutif", " 00:24", 20000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }

    else if (stasiunber == 2 && stasiundat == 1)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: Joglosemarkerto (Rp.150.000) 15:10\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "Joglosemarkerto", "Lempuyangan (LPN)", "Solo Balapan (SLO)", "Ekonomi", "15:10", 150000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }

    else if (stasiunber == 2 && stasiundat == 5)
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(50) << "TIKET YANG TERSEDIA" << setw(51) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "1. Kereta: Gayabaru Malam Selatan (Rp.350.000) 19:15\n";
        cout << "2. Kereta: Jayakarta (Rp.350.000) 19:04\n";
        cout << "3. Kereta: Pasundan (Rp.250.000) 18:18\n";
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        char pilihan;
        cout << "Pilih kereta: ";
        cin >> pilihan;

        if (pilihan == '1')
        {
            tiket[tiketCount++] = {currentUser, "Gayabaru Malam Selatan", "Lempuyangan (LPN)", "Surabaya Gubeng (SGU)", "Campuran", "19:15", 350000};
        }

        else if (pilihan == '2')
        {
            tiket[tiketCount++] = {currentUser, "Turangga", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Ekonomi", " 19:04", 350000};
        }

        else if (pilihan == '3')
        {
            tiket[tiketCount++] = {currentUser, "Turangga", "Yogyakarta (YK)", "Surabaya Gubeng (SGU)", "Ekonomi", " 18:18", 250000};
        }

        else
        {
            cout << "Pilihan tidak valid.\n";
            return;
        }

        cout << "Tiket berhasil dipesan!\n";
        system("pause");
    }
    else
    {
        cout << "Maaf, tiket untuk rute ini belum tersedia.\n";
        system("pause");
    }
}

void lihatTiket(const string &currentUser)
{
    system("cls");
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    cout << setfill(' ');
    cout << "|" << setw(50) << "TIKET ANDA : " << setw(51) << "|" << endl;
    cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
    bool found = false;

    // Header tabel tiket
    cout << setfill(' ');
    cout << setw(15) << left << "Kereta" 
         << setw(20) << left << "Stasiun Asal"
         << setw(20) << left << "Stasiun Tujuan"
         << setw(10) << left << "Kelas"
         << setw(15) << left << "Jam"
         << setw(15) << left << "Harga (Rp)" << endl;
    cout << string(102, '-') << endl;

    // Cari tiket berdasarkan username
    for (int i = 0; i < tiketCount; i++)
    {
        if (tiket[i].username == currentUser)
        {
            cout << setw(15) << left << tiket[i].kereta
                 << setw(20) << left << tiket[i].stasiunAsal
                 << setw(20) << left << tiket[i].stasiunTujuan
                 << setw(10) << left << tiket[i].kelas
                 << setw(15) << left << tiket[i].jamKeberangkatan
                 << setw(15) << left << fixed << setprecision(2) << tiket[i].harga
                 << endl;
            found = true;
        }
    }

    // Jika tidak ada tiket ditemukan
    if (!found)
    {
        cout << "\n[Anda belum membeli tiket.]\n";
    }
    else
    {
        cout << string(102, '-') << endl;
    }

    cout << "Press any key to continue...";
    cin.ignore();
    cin.get();

}

// Fungsi untuk menghapus user dari sistem
void hapusUser(const string &username) { // Parameter referensi konstan string ini digunakan agar,
                                        // fungsi bisa membaca nilai username yang diberikan, tetapi tidak mengubahnya.
    bool found = false; // di set ke false dulu yg artinya username yang dicari belum ditemukan
    for (int i = 0; i < usersekarang; i++) {
        if (user[i][0] == username) { // membandingan indeks i dengan username(userSekarang) yang ingin dihapus
            found = true; // buat penanda username ditemukan

            // Geser semua data setelah elemen yang dihapus
            // Jadi ibaratnya apabila userSekarang yang sedang digunakan user ini memilih Logout kan otomatis langsung kehapus,
            // nah data array yang disimpan juga sebelum2nya ini akan bergeser menggantikan tempat array yang kosong karena dihapus ini 

            for (int j = i; j < usersekarang - 1; j++) {
                user[j][0] = user[j + 1][0];
                user[j][1] = user[j + 1][1];
            }
            usersekarang--; // Kurangi jumlah user
            break;
        }
    }
    if (found) { // username yang ingin dihapus ditemukan 
        cout << "Logout berhasil. Akun Anda telah dihapus.\n";
    } else { // sama aja dengan found == false
        cout << "Akun tidak ditemukan.\n";
    }
}

// yang ini gausah diotak atik
int main()
{
    char pilihan;
    string currentUser;

    do
    {
        system("cls");
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(71) << "SELAMAT DATANG DI PEMESANAN TIKET KERETA API YOGYAKARTA" << setw(30) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << setfill(' ');
        cout << "|" << setw(20) << "(1) REGISTER " << setw(15) << "|" << setw(20) << "(2) LOGIN " << setw(15) << "|" << setw(20) << "(3) KELUAR " << setw(11) << "|" << endl;
        cout << "+" << setw(100) << setfill('-') << "-" << "+" << endl;
        cout << "Pilih menu (1/2/3) : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case '1':
            registerUser();
            break;
        case '2':
            if (loginUser(currentUser))
            {
                char menu;
                do
                {
                system("cls");
                cout << "+" << setw(100) << setfill('-') << "-"  << "+" << endl;
                cout << setfill(' ');
                cout << "|" << setw(64) << "KERETA API YOGYAKARTA" << setw(37) << "|" << endl;
                cout << "+" << setw(100) << setfill('-') << "-"  << "+" << endl;                   
                cout << "\n(1) BELI TIKET\n";
                cout << "(2) LIHAT TIKET\n";
                cout << "(3) LOGOUT\n";
                cout << "\nPilih menu (1/2/3) : ";
                cin >> menu;

                    switch (menu)
                    {
                    case '1':
                        pesantiket(currentUser);
                        break;
                    case '2':
                        lihatTiket(currentUser);
                        break;
                    case '3':
                        {
                        hapusUser(currentUser); // Hapus user yang logout
                        currentUser.clear();    // Kosongkan nama user

                        char kembali;
                        cout << "Apakah Anda ingin kembali ke menu utama? (y/n): ";
                        cin >> kembali;

                        if (tolower(kembali) == 'y') {
                            pilihan = '0'; // Mengarahkan kembali ke menu utama
                        } else {
                            cout << "Terima kasih telah menggunakan layanan kami. Sistem akan keluar.\n";
                            pilihan = '3'; // Keluar dari program
                        }
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid.\n";
                    }
                } while (menu != '3');
            }
            break;
        case '3':
            cout << "Terima kasih. Silahkan datang kembali.\n";
            break;
        default:
            cout << "Pilihan tidak valid. Coba lagi.\n";
            break;
        }
    } while (pilihan != '3');

    return 0;
}