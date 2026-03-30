//2praktinis
#include <iostream>
#include <string>
using namespace std;

const int MAX_MOKINIU = 100;
const int MAX_PAZYMIU = 10;

string vardai[MAX_MOKINIU];
int pazymiai[MAX_MOKINIU][MAX_PAZYMIU];
int pazymiuKiekis[MAX_MOKINIU];

int mokiniuKiekis = 0;

void pridetiMokini() {
    if (mokiniuKiekis >= MAX_MOKINIU) {
        cout << "Pasiektas mokiniu limitas!\n";
        return;
    }

    cout << "Iveskite mokinio varda: ";
    cin >> vardai[mokiniuKiekis];

    cout << "Kiek pazymiu ivesti (max 10): ";
    cin >> pazymiuKiekis[mokiniuKiekis];

    if (pazymiuKiekis[mokiniuKiekis] > MAX_PAZYMIU) {
        cout << "Max 10\n";
        pazymiuKiekis[mokiniuKiekis] = MAX_PAZYMIU;
    }

    for (int i = 0; i < pazymiuKiekis[mokiniuKiekis]; i++) {
        int pazymys;
        do {
            cout << "Pazymys " << i + 1 << " (0-10): ";
            cin >> pazymys;
            if (pazymys < 0 || pazymys > 10) {
                cout << "Tik nuo 1-10.\n";
            }
        } while (pazymys < 0 || pazymys > 10);
        pazymiai[mokiniuKiekis][i] = pazymys;
    }

    mokiniuKiekis++;
}

void rodytiVisus() {
    for (int i = 0; i < mokiniuKiekis; i++) {
        cout << vardai[i] << ": ";
        for (int j = 0; j < pazymiuKiekis[i]; j++) {
            cout << pazymiai[i][j] << " ";
        }
        cout << endl;
    }
}

void rodytiViena() {
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            cout << vardai[i] << ": ";
            for (int j = 0; j < pazymiuKiekis[i]; j++) {
                cout << pazymiai[i][j] << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << "Mokinys nerastas\n";
}

void atnaujintiPazymi() {
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            int nr;
            cout << "Kurio pazymio nr. keisti (1-" << pazymiuKiekis[i] << "): ";
            cin >> nr;

            int naujas;
            do {
                cout << "Naujas pazymys (0-10): ";
                cin >> naujas;
                if (naujas < 0 || naujas > 10) {
                    cout << " Tik nuo 1-10 .\n";
                }
            } while (naujas < 0 || naujas > 10);

            pazymiai[i][nr - 1] = naujas;
            return;
        }
    }

    cout << "Mokinys nerastas\n";
}

void pasalintiMokini() {
    string vardas;
    cout << "Iveskite mokinio varda: ";
    cin >> vardas;

    for (int i = 0; i < mokiniuKiekis; i++) {
        if (vardai[i] == vardas) {
            for (int j = i; j < mokiniuKiekis - 1; j++) {
                vardai[j] = vardai[j + 1];
                pazymiuKiekis[j] = pazymiuKiekis[j + 1];

                for (int k = 0; k < MAX_PAZYMIU; k++) {
                    pazymiai[j][k] = pazymiai[j + 1][k];
                }
            }
            mokiniuKiekis--;
            cout << "Mokinys pasalintas!\n";
            return;
        }
    }

    cout << "Mokinys nerastas\n";
}

int main() {
    int pasirinkimas;
    do {

        cout << "1. Prideti mokini\n";
        cout << "2. Rodyti visus mokinius\n";
        cout << "3. Rodyti viena mokini\n";
        cout << "4. Atnaujinti pazymi\n";
        cout << "5. Pasalinti mokini\n";
        cout << "0. Iseiti\n";
        cout << "Pasirinkimas: ";
        cin >> pasirinkimas;

        switch (pasirinkimas) {
            case 1: pridetiMokini(); break;
            case 2: rodytiVisus(); break;
            case 3: rodytiViena(); break;
            case 4: atnaujintiPazymi(); break;
            case 5: pasalintiMokini(); break;
        }

    } while (pasirinkimas != 0);

    return 0;
}
