#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <iomanip>

using namespace std;

const int sonsuz = numeric_limits<int>::max();

struct Kenar {
    int hedef;
    int agirlik;
};

struct Dugum {
    int id;
    int mesafe;

    bool operator>(const Dugum& diger) const {
        return mesafe > diger.mesafe;
    }
};

bool BellmanFord(int dugumSayisi, const vector<vector<Kenar>>& komsulukListesi, int baslangic, vector<int>& mesafeler) {
    mesafeler.assign(dugumSayisi, sonsuz);
    mesafeler[baslangic] = 0;
    for (int i = 0; i < dugumSayisi - 1; ++i) {
        for (int u = 0; u < dugumSayisi; ++u) {
            for (const auto& kenar : komsulukListesi[u]) {
                if (mesafeler[u] != sonsuz && mesafeler[u] + kenar.agirlik < mesafeler[kenar.hedef]) {
                    mesafeler[kenar.hedef] = mesafeler[u] + kenar.agirlik;
                }
            }
        }
    }
    for (int u = 0; u < dugumSayisi; ++u) {
        for (const auto& kenar : komsulukListesi[u]) {
            if (mesafeler[u] != sonsuz && mesafeler[u] + kenar.agirlik < mesafeler[kenar.hedef]) {
                return true;
            }
        }
    }
    return false;
}

vector<int> Dijkstra(int dugumSayisi, const vector<vector<Kenar>>& komsulukListesi, int baslangic) {
    vector<int> mesafeler(dugumSayisi, sonsuz);
    mesafeler[baslangic] = 0;
    priority_queue<Dugum, vector<Dugum>, greater<Dugum>> oncelikKuyrugu;
    oncelikKuyrugu.push({ baslangic, 0 });

    while (!oncelikKuyrugu.empty()) {
        Dugum mevcut = oncelikKuyrugu.top();
        oncelikKuyrugu.pop();
        int u = mevcut.id;

        if (mevcut.mesafe > mesafeler[u]) continue;

        for (const auto& kenar : komsulukListesi[u]) {
            if (mesafeler[u] + kenar.agirlik < mesafeler[kenar.hedef]) {
                mesafeler[kenar.hedef] = mesafeler[u] + kenar.agirlik;
                oncelikKuyrugu.push({ kenar.hedef, mesafeler[kenar.hedef] });
            }
        }
    }
    return mesafeler;
}

vector<vector<int>> Johnson(int dugumSayisi, vector<vector<Kenar>>& komsulukListesi) {
    vector<vector<int>> sonuc(dugumSayisi, vector<int>(dugumSayisi, sonsuz));
    vector<vector<Kenar>> sanalKomsulukListesi = komsulukListesi;
    sanalKomsulukListesi.push_back({});

    for (int i = 0; i < dugumSayisi; ++i) {
        sanalKomsulukListesi[dugumSayisi].push_back({ i, 0 });
    }

    vector<int> potansiyellerTam;
    if (BellmanFord(dugumSayisi + 1, sanalKomsulukListesi, dugumSayisi, potansiyellerTam)) {
        cerr << " Negatif agirlikli dongu tespit edildi. Johnson algoritmasi uygulanamaz." << endl;
        return {};
    }

    vector<int> potansiyeller(potansiyellerTam.begin(), potansiyellerTam.begin() + dugumSayisi);

    // Kenarlarý yeniden aðýrlýklandýr
    vector<vector<Kenar>> yenidenAgirliklandirilmis = komsulukListesi;
    for (int u = 0; u < dugumSayisi; ++u) {
        for (auto& kenar : yenidenAgirliklandirilmis[u]) {
            kenar.agirlik += potansiyeller[u] - potansiyeller[kenar.hedef];
        }
    }

    for (int u = 0; u < dugumSayisi; ++u) {
        vector<int> d = Dijkstra(dugumSayisi, yenidenAgirliklandirilmis, u);
        for (int v = 0; v < dugumSayisi; ++v) {
            if (d[v] != sonsuz) {
                sonuc[u][v] = d[v] - potansiyeller[u] + potansiyeller[v];
            }
        }
    }

    return sonuc;
}

int main() {
    int dugumSayisi, kenarSayisi;
    cout << "Dugum sayisini giriniz: ";
    cin >> dugumSayisi;
    cout << " Kenar sayisini giriniz: ";
    cin >> kenarSayisi;

    vector<vector<Kenar>> komsulukListesi(dugumSayisi);
    cout << " Kenarlari giriniz (kaynak hedef agirlik):" << endl;
    for (int i = 0; i < kenarSayisi; ++i) {
        int kaynak, hedef, agirlik;
        cin >> kaynak >> hedef >> agirlik;
        if (kaynak >= 0 && kaynak < dugumSayisi && hedef >= 0 && hedef < dugumSayisi) {
            komsulukListesi[kaynak].push_back({ hedef, agirlik });
        }
        else {
            cerr << " Gecersiz dugum indeksi!" << endl;
            --i;
        }
    }

    auto mesafelerMatrisi = Johnson(dugumSayisi, komsulukListesi);
    if (mesafelerMatrisi.empty()) return 1;

    cout << "\n En kisa yollar matrisi:\n";
    for (int i = 0; i < dugumSayisi; ++i) {
        for (int j = 0; j < dugumSayisi; ++j) {
            if (mesafelerMatrisi[i][j] == sonsuz) cout << setw(5) << " SONSUZ";
            else cout << setw(5) << mesafelerMatrisi[i][j];
        }
        cout << "\n";
    }

    return 0;
}