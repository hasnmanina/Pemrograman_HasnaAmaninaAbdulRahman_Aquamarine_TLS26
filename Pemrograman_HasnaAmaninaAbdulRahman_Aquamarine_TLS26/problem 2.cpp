#include <iostream>
#include <string>

using namespace std;

int main() {
    string pesanAsli;
    
    // Input pesan asli dari pengguna
    cout << "Masukkan pesan asli (huruf KAPITAL tanpa spasi): ";
    cin >> pesanAsli;
    
    string pesanSandi = "";
    int panjang = pesanAsli.length();
    
    if (panjang > 0) {
        // Huruf pertama tidak mengalami perubahan
        pesanSandi += pesanAsli[0];
        
        // Iterasi mulai dari huruf kedua (indeks 1)
        for (int i = 1; i < panjang; ++i) {
            // Konversi karakter ke nilai alfabet (A=1, B=2, ..., Z=26)
            int nilaiCurr = pesanAsli[i] - 'A' + 1;
            int nilaiPrev = pesanAsli[i - 1] - 'A' + 1;
            
            // Pergeseran nilai berdasarkan huruf sebelumnya
            int nilaiBaru = nilaiCurr + nilaiPrev;
            
            // Handling jika pergeseran melewati 'Z' (melebihi 26)
            if (nilaiBaru > 26) {
                nilaiBaru = (nilaiBaru - 1) % 26 + 1;
            }
            
            // Konversi kembali dari nilai alfabet ke karakter
            char charBaru = (char)(nilaiBaru + 'A' - 1);
            pesanSandi += charBaru;
        }
    }
    
    // Tampilkan hasil enkripsi
    cout << "\nPesan Sandi: " << pesanSandi << endl;
    
    return 0;
}