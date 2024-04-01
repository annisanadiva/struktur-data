#include <iostream>
#include <string>

using namespace std;

// mendefinisikan structure tamu untuk menyimpan informasi tamu dan pointer ke tamu berikutnya
struct Tamu {
    string nama;
    int nomorKamar;
    Tamu* next;
};

// mendefinisikan class hotel untuk menyimpan daftar tamu dan status kamar
class Hotel {
private:
    static const int NO_KAMAR = 10;
    Tamu* daftarTamu;
    Tamu* kamar[NO_KAMAR];
public:
    Hotel() {
        daftarTamu = nullptr;
        for (int i = 0; i < NO_KAMAR; ++i) {
            kamar[i] = nullptr;
        }
    }

    // fungsi untuk menambahkan data tamu baru, jika nomor kamar tidak valid pesan/notifikasi kesalahan akan ditampilkan
    void tambahTamu(const string& nama, int nomorKamar) {
        if (nomorKamar < 1 || nomorKamar > NO_KAMAR) {
            cout << "Nomor kamar tidak valid." << endl;
            return;
        }
        Tamu* tamuBaru = new Tamu;
        tamuBaru -> nama = nama;
        tamuBaru -> nomorKamar = nomorKamar;
        tamuBaru -> next = daftarTamu;
        daftarTamu = tamuBaru;
        kamar[nomorKamar - 1] = tamuBaru;
        cout << "Tamu " << nama << " telah ditambahkan ke kamar " << nomorKamar << "." << endl;
    }

    // fungsi untuk menampilkan daftar tamu beserta nomor kamar yang telah diinput sebelumnya
    void tampilDaftarTamu() {
        cout << "Daftar Tamu:" << endl;
        Tamu* current = daftarTamu;
        while (current != nullptr) {
            cout << "Nama: " << current -> nama << ", Kamar: " << current -> nomorKamar << endl;
            current = current -> next;
        }
    }

    // fungsi untuk mencari tamu dan menampilkan nomor kamar berdasarkan nama tamu
    void cariTamu(const string& nama) {
        Tamu* current = daftarTamu;
        while (current != nullptr) {
            if (current -> nama == nama) {
                cout << "Tamu " << nama << " ditemukan di kamar " << current -> nomorKamar << "." << endl;
                return;
            }
            current = current -> next;
        }
        cout << "Tamu " << nama << " tidak ditemukan." << endl;
    }
};

int main() {
    Hotel hotel;
    char pilih;

    // fitur-fitur yang terdapat di dalam program yang dapat dipilih oleh user
    do {
        cout << "Silakan Pilih Menu:" << endl;
        cout << "1. Tambah Tamu" << endl;
        cout << "2. Tampilkan Daftar Tamu" << endl;
        cout << "3. Cari Tamu" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilih;

        // pengimplementasian switch case untuk proses pilihan user, program akan terus berjalan hingga pengguna memilih fitur keluar (fitur no. 4)
        switch (pilih) {
            case '1': {
                string nama;
                int nomorKamar;
                cout << "Masukkan nama tamu: ";
                cin >> nama;
                cout << "Masukkan nomor kamar: ";
                cin >> nomorKamar;
                hotel.tambahTamu(nama, nomorKamar);
                break;
            }
            case '2':
                hotel.tampilDaftarTamu();
                break;
            case '3': {
                string nama;
                cout << "Masukkan nama tamu yang ingin dicari: ";
                cin >> nama;
                hotel.cariTamu(nama);
                break;
            }
            case '4':
                cout << "Program selesai. Terima Kasih!" << endl;
                break;
            default:
                cout << "Pilihan anda tidak valid. Mohon coba lagi." << endl;
        }
    } while (pilih != '4');

    return 0;
}
