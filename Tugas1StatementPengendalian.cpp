#include <iostream>
using namespace std;

float kuis, responsi, tugas, nilaiAkhir;
char pilih, grade;
string backtomenu;

int main() {
    do {
        system("cls");
        cout << "-------------------------------\n";
        cout << "NILAI AKADEMIK MAHASISWA UPNVYK\n";
        cout << "-------------------------------\n";
        cout << "Masukkan nilai berikut ini :\n";
        cout << "Nilai Kuis\t: ";
        cin >> kuis;
        cout << "Nilai Responsi\t: ";
        cin >> responsi;
        cout << "Nilai Tugas\t: ";
        cin >> tugas;
        cout << "\nApakah mahasiswa aktif dalam praktikum? (y/n) : ";
        cin >> pilih;
        cout << endl;

        nilaiAkhir = kuis * 0.35 + responsi * 0.4 + tugas * 0.25;
        if (pilih == 'y') {
            if (nilaiAkhir < 85) {
                nilaiAkhir += 5;
            }
        }

        if (nilaiAkhir >= 85) {
            grade = 'A';
        } else if (nilaiAkhir >= 70) {
            grade = 'B';
        } else if (nilaiAkhir >= 50) {
            grade = 'C';
        } else {
            grade = 'D';
        }

        // Menghapus penggunaan Switch yang sebelumnya ada, agar menjadi lebih efektif.
        // (Tidak lagi meng'cout'kan berdasarkan Grade di Switch Case)

        cout << "Nilai Kuis\t: " << kuis << endl;
        cout << "Nilai Responsi\t: " << responsi << endl;
        cout << "Nilai Tugas\t: " << tugas << endl;
        cout << "Keaktifan\t: " << (pilih == 'y' || pilih == 'Y' ? "Mahasiswa Aktif" : "Bukan Mahasiswa Aktif") << endl;
        cout << "Nilai Akhir\t: " << nilaiAkhir << endl;
        cout << "Grade\t\t: " << grade << endl;

        cout << "\nPeriksa ulang kembali nilai? (y/n) : ";
        cin >> backtomenu;
    } while (backtomenu == "Y" || backtomenu == "y");
}
