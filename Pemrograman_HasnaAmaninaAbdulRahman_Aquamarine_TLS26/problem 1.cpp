#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    
    // Input jumlah astronot (N) dan nilai awal K
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;
    
    // Inisialisasi daftar astronot [1, 2, ..., N]
    vector<int> astronaut;
    for (int i = 1; i <= N; ++i) {
        astronaut.push_back(i);
    }
    
    int currentPosition = 0;
    
    cout << "\n--- Urutan Eliminasi ---" << endl;
    
    // Perulangan selama astronot tersisa lebih dari 1
    while (astronaut.size() > 1) {
        // Hitung indeks astronot yang dieliminasi dengan aritmatika modular
        int elimIndex = (currentPosition + K - 1) % astronaut.size();
        
        // Ambil nomor astronot yang tereliminasi
        int eliminatedAstronaut = astronaut[elimIndex];
        cout << "Astronot " << eliminatedAstronaut << " dieliminasi." << endl;
        
        // Hapus astronot dari daftar
        astronaut.erase(astronaut.begin() + elimIndex);
        
        // Update posisi untuk langkah berikutnya
        currentPosition = elimIndex;
        
        // Aturan perubahan nilai K
        if (eliminatedAstronaut % 2 == 0) {
            K += 2; // Jika genap, K bertambah 2
        } else {
            K -= 1; // Jika ganjil, K berkurang 1
        }
        
        // Aturan batas minimum K
        if (K < 2) {
            K = 2;
        }
    }
    
    // Output astronot terakhir yang bertahan
    cout << "\n-----------------------------------" << endl;
    cout << "Astronot Terakhir yang Bertahan: " << astronaut[0] << endl;
    
    return 0;
}