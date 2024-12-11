#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Struct node untuk lagu
struct lagu {
    string judul;
    string artist;
    string album;
    lagu* next;
};

//Struct node untuk playlist
struct playlist {
    string nama;
    lagu* daftarlagu;
    playlist* next;
};

//Fungsi buat bikin lagu baru
lagu* buatlagu(string& judul, string& artist, string& album){
    lagu* lagu_baru = new lagu();
    lagu_baru->judul = judul;
    lagu_baru->artist = artist;
    lagu_baru->album = album;
    lagu_baru->next = nullptr;
    return lagu_baru;
}

//Menambahkan lagu ke playlist
void tambah_lagu(lagu*& playlist, string& judul, string& artist, string& album){
    lagu* lagu_baru = buatlagu(judul, artist, album);
    if(!playlist) {
        playlist = lagu_baru;
    } else {
        lagu* temp = playlist;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = lagu_baru;
    }
    cout << "Lagu " << judul << " oleh " << artist << " dari album " << album << " berhasil ditambahkan!\n";
}

//Menghapus lagu dari playlist berdasarkan judul 
void hapus_lagu(lagu*& playlist, string& judul){
    if(!playlist){
        cout << "Playlist kosong.\n";
        return;
    }
    lagu* temp = playlist;
    lagu* prev = nullptr;

    while(temp && temp->judul != judul){
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Lagu " << judul << " tidak ditemukan.\n";
        return;
    }
    if (!prev) {
        playlist = playlist->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Lagu " << judul << " berhasil dihapus.\n";
}

void createplaylist(playlist*& head, string nama_playlist) {
    playlist* playlist_baru = new playlist();
    playlist_baru->nama = nama_playlist;
    playlist_baru->daftarlagu = nullptr;
    playlist_baru->next = nullptr;

    if (!head) {
        head = playlist_baru;
    } else {
        playlist* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = playlist_baru;
    }
    cout << "Playlist " << nama_playlist << " telah berhasil dibuat!\n";
}


void showplaylist(lagu* playlist) {
    if (!playlist) {
        cout << "Playlist masih kosong.\n";
        return;
    }
    lagu* temp = playlist;
    cout << "Daftar lagu dalam playlist:\n";
    while (temp) {
        cout << "Judul: \n" << temp->judul
         << "Artist: \n" << temp->artist
         << "Album: " << temp->album << endl;
        temp = temp->next;
    }
    
}

void showplaylist2(playlist* head) {
    if (!head) {
        cout << "Playlist tidak ditemukan.\n";
        return;
    }

    playlist* temp = head;
    cout << "Daftar Playlist:\n";
    while (temp) {
        cout << "Playlist: " << temp->nama << endl;
        temp = temp->next;
    }
}

void urutlagubdsr_artist(lagu*& head) {
        if (!head || !head->next){
            return;
        }
        for (lagu* i = head; i != nullptr; i = i->next) {
            for (lagu* j = i->next; j != nullptr; j = j->next) {
                if (i->artist > j->artist) {
                    swap(i->judul, j->judul);
                    swap(i->artist, j->artist);
                    swap(i->album, j->album);
                }
            }
        }

        cout << "Playlist diurutkan berdasarkan Artist.\n";
    }

void urutlagubdsr_judul() {
        if (!head || !head->next){
            return;
        }
        for (lagu* i = head; i != nullptr; i = i->next) {
            for (lagu* j = i->next; j != nullptr; j = j->next) {
                if (i->judul > j->judul) {
                    swap(i->judul, j->judul);
                    swap(i->artist, j->artist);
                    swap(i->album, j->album);
                }
            }
        }

        cout << "Playlist diurutkan berdasarkan Judul.\n";
    }

void ubahtxt (lagu* head, const string& namafile){
    ofstream file(namafile);
    if (!file.is_open()){
        cout << "Error: Tidak bisa membuka file" << namafile << endl;
        return;
    }
    lagu* current = head;
    while (current){
        file << "Judul: " << current -> judul << endl;
        file << "Artist: " << current -> artist << endl;
        current = current -> next;
    }
    file.close();
    cout << "Playlist telah di save ke" << namafile << endl;
}

//fungsi untuk nampilin playlist di layar
void display(lagu* head) {
    if (!head) {
        cout << "Playlist kosong" << endl;
        return;
    }

    lagu* current = head;
    while (current) {
        cout << "Judul: " << current->judul << ", Artist: " << current->artist << endl;
        current = current->next;
    }
}

int main () {
    lagu* playlist = nullptr;
    string judul;
    string artist;
    string album;
    string namaplaylist;
    int pilih;
    
    cout << "Aplikasi Spotify\nPilih angka: \n";
    cout << "1. Tambah lagu\n";
    cout << "2. Buat Playlist\n";
    cout << "3. Hapus lagu\n";
    cout << "4. Lihat playlist\n";
    cout << "5. Urutkan lagu dalam playlist\n";
    cout << "6. Simpan playlist ke file\n";
    cout << "7. Baca playlist dari file\n";
    cout << "8. Keluar\n";
    cin >> pilih;
    cin.ignore();

    switch (pilih){
        case 1:
            cout << "Masukkan judul lagu: ";
            getline(cin, judul);
            cout << "Masukkan nama penyanyi: ";
            getline(cin, artist);
            cout << "Masukkan nama album: ";
            getline(cin, album);
            tambah_lagu(playlist, judul, artist, album);
            break;       
            
        case 2:
            cout << "Masukkan judul lagu yang ingin dihapus: ";
            getline(cin, judul);
            hapus_lagu(playlist, judul);
            break;
        
        case 3:
            showplaylist(playlist);
            break;
        
        case 4:
            urutlagubdsr_artist(playlist);
            break;
        
        case 5;
        
        
    }
        


}