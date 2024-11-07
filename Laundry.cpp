#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // untuk mengatur presisi desimal
using namespace std;

bool login() {
    const string usernameBenar = "admin"; // username yang benar
    const string passwordBenar = "123";   // password yang benar
    string username, password;
    cout << "==========================" << endl;
    cout << "       Login Laundry       " << endl;
    cout << "==========================" << endl;
    cout << "Username: "; cin >> username;
    cout << "Password: "; cin >> password;

    if (username == usernameBenar && password == passwordBenar) {
        cout << "Login Berhasil!" << endl;
        return true;
    } else {
        cout << "Username atau password salah. Silakan coba lagi." << endl;
        return false;
    }
}
// untuk mencetak bon
void cetakBon(const string& nama, const string& nomorHp, const string& alamat, const string& tanggal, const string& layanan, float berat, float hargaPerKg) {
    float total = berat * hargaPerKg;

    cout << "===========================" << endl;
    cout << "      LAUNDRY BERKAH          " << endl;
    cout << "===========================" << endl;
    cout << "Tanggal      : " << tanggal << endl;
    cout << "Nama         : " << nama << endl;
    cout << "No. HP       : " << nomorHp << endl;
    cout << "Alamat       : " << alamat << endl;
    cout << "Layanan      : " << layanan << endl;
    cout << "Berat        : " << fixed << setprecision(2) << berat << " kg" << endl;
    cout << "Harga/kg     : Rp " << hargaPerKg << endl;
    cout << "===========================" << endl;
    cout << "Total Harga  : Rp " << total << endl;
    cout << "===========================" << endl;
    cout << "Terima Kasih Telah Menggunakan Layanan Kami!" << endl;
    cout << "===========================" << endl;
}

int main() {
    vector<string> nama, nomorHp, alamat, tanggal, layanan;
    vector<float> beratLaundry;
    string n, hp, al, tgl = __DATE__;
    float kg;
    int pilihan, h, pilihanLayanan;
    const float hargaPerKgReguler = 5000;
    const float hargaPerKgEkspres = 8000;
    const float hargaPerKgCuciKering = 10000;
    char t;
    bool lanjut = true;

    while(!login()) {}

    do {
        cout << endl;
        cout << "   Projek Alpro-Laundry" << endl;
        cout << "   Kelompok 1 : Ananda Fahrizal Assidiq, Nugraha Adani, M Zamy Alfiansyah" << endl;
        cout << endl;
        cout << "=============================" << endl;
        cout << "    ==Laundry Berkah==\n";
        cout << "=============================" << endl;
        cout << " 1. Tambah Data Pelanggan\n";
        cout << " 2. Lihat Data Pelanggan\n";
        cout << " 3. Hapus Data Pelanggan\n";
        cout << " 4. Cetak Bon Laundry\n";
        cout << " 5. Keluar\n";
        cout << "=============================" << endl;
        cout << " Masukkan Nomor Pilihan (1-5): "; cin >> pilihan;
        cout << "=============================" << endl;
        cin.ignore();
        system("cls");

        switch (pilihan) {
        case 1:
            cout << "=============================" << endl;
            cout << "Nama Pelanggan     : "; getline(cin, n);
            nama.push_back(n);

            cout << "Nomor Hp           : "; cin >> hp; cin.ignore();
            nomorHp.push_back(hp);

            cout << "Alamat             : "; getline(cin, al);
            alamat.push_back(al);

            tanggal.push_back(tgl);

            cout << "\nPilih Layanan Laundry:" << endl;
            cout << "1. Cuci Reguler (Rp " << hargaPerKgReguler << " per kg)" << endl;
            cout << "2. Cuci Ekspres (Rp " << hargaPerKgEkspres << " per kg)" << endl;
            cout << "3. Cuci Kering (Rp " << hargaPerKgCuciKering << " per kg)" << endl;
            cout << "Masukkan pilihan layanan (1-3): ";
            cin >> pilihanLayanan;

            // pilihan layanan dan simpan
            float hargaPerKg;
            switch (pilihanLayanan) {
                case 1:
                    layanan.push_back("Cuci Reguler");
                    hargaPerKg = hargaPerKgReguler;
                    break;
                case 2:
                    layanan.push_back("Cuci Ekspres");
                    hargaPerKg = hargaPerKgEkspres;
                    break;
                case 3:
                    layanan.push_back("Cuci Kering");
                    hargaPerKg = hargaPerKgCuciKering;
                    break;
                default:
                    cout << "Pilihan layanan tidak valid. Menggunakan Cuci Reguler." << endl;
                    layanan.push_back("Cuci Reguler");
                    hargaPerKg = hargaPerKgReguler;
                    break;
            }

            cout << endl;
            cout << "Berat Laundry (contoh: 1 untuk 1 kg atau 1.5 untuk 1.5 kg): "; cin >> kg;
            beratLaundry.push_back(kg);

            cout << "\nData Telah Ditambahkan\n";
            cout << "Kembali ke menu utama? (y/n): "; cin >> t;

            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 2:
            for (int i = 0; i < nama.size(); i++) {
                cout << "=======================================" << endl;
                cout << endl;
                cout << " Data Pelanggan ke     : " << i + 1 << endl;
                cout << " Nama                  : " << nama[i] << endl;
                cout << " Tgl Masuk             : " << tanggal[i] << endl;
                cout << " Layanan               : " << layanan[i] << endl;
                cout << " No Hp                 : " << nomorHp[i] << endl;
                cout << " Alamat                : " << alamat[i] << endl;
                cout << " Subtotal              : Rp " << beratLaundry[i] << " kg x " << (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                     << " : Rp " << beratLaundry[i] * (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                    << endl;
                cout << endl;
            }
            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;

            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 3:
            for (int i = 0; i < nama.size(); i++) {
                cout << "=======================================" << endl;
                cout << endl;
                cout << " Data Pelanggan ke     : " << i + 1 << endl;
                cout << " Nama                  : " << nama[i] << endl;
                cout << " Tgl Masuk             : " << tanggal[i] << endl;
                cout << " Layanan               : " << layanan[i] << endl;
                cout << " No Hp                 : " << nomorHp[i] << endl;
                cout << " Alamat                : " << alamat[i] << endl;
                cout << " Subtotal              : Rp " << beratLaundry[i] << " kg x " << (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                     << " : Rp " << beratLaundry[i] * (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                    << endl;
                cout << endl;
            }
            cout << "\nData Pelanggan Ke Berapa Yang Ingin Dihapus? (Masukkan Angka): ";
            cin >> h;

            if (h > 0 && h <= nama.size()) {
                nama.erase(nama.begin() + h - 1);
                nomorHp.erase(nomorHp.begin() + h - 1);
                alamat.erase(alamat.begin() + h - 1);
                layanan.erase(layanan.begin() + h - 1);
                beratLaundry.erase(beratLaundry.begin() + h - 1);

                cout << "\nData Pelanggan ke-" << h << " Telah Dihapus" << endl;
            } else {
                cout << "\nIndeks tidak valid!" << endl;
            }

            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 4:
            cout << "\nMasukkan nomor pelanggan yang ingin dicetak bon (1 - " << nama.size() << "): ";
            cin >> h;

            if (h > 0 && h <= nama.size()) {
                int index = h - 1;
                cetakBon(nama[index], nomorHp[index], alamat[index], tanggal[index], layanan[index], beratLaundry[index],
                    	layanan[index] == "Cuci Reguler" ? hargaPerKgReguler :
                        layanan[index] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering);
            } else {
                cout << "Nomor pelanggan tidak valid!" << endl;
            }

            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 5:
            lanjut = false;
            break;

        default:
            cout << "\nPilihan yang Anda pilih tidak tersedia, Kembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;
        }
    } while (lanjut);

    cout << "Program selesai" << endl;
    return 0;
}
