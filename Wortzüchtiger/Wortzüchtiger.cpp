#include <iostream>
using namespace std;

int main()
{
    int laufzeit = 1;
    const int zeichenbegrenzung = 500;
    char satz[zeichenbegrenzung];
    string anfangsbuchstaben[zeichenbegrenzung];

    // Initialisieren:
    for (int i = 0; i < zeichenbegrenzung; i++) {
        anfangsbuchstaben[i] = "\0";
        satz[i] = '\0';
    }

    while (laufzeit == 1) {
        cout << "Geben Sie einen schaendlichen Satz ein: \n";
        cin.getline(satz, zeichenbegrenzung);
        satz[0] = toupper(satz[0]);

        for (int i = 1; i < zeichenbegrenzung; i++)
        {
            if (satz[i] == ',' || satz[i] == '.' || satz[i] == '?' || satz[i] == '!' || satz[i] == '"' || satz[i] == '\'') {
                anfangsbuchstaben[i] = satz[i];
            }
            if (satz[i - 1] == ' ') {
                anfangsbuchstaben[i] = satz[i];
            }
        }

        cout << "\nAeusserst schaendlich. Wir haben das fuer Sie korrigiert:\n\n";
        // cout << satz << endl;

        if (satz[0] == '"') {
            cout << satz[0] << satz[1] << "-Wort";
        }
        else {
            cout << satz[0] << "-Wort";
        }
        for (int i = 0; i < zeichenbegrenzung-1; i++) {
            if (anfangsbuchstaben[i] == " ") {
                cout << "";
            }
            else if (anfangsbuchstaben[i] == "") {
                continue;
            }
            else if (satz[i] == ',' || satz[i] == '.' || satz[i] == '?' || satz[i] == '!' || satz[i] == '"' || satz[i] == '\'') {
                cout << satz[i];
            }
            else {
                cout << " " << anfangsbuchstaben[i];
                cout << "-Wort";
            }

        }
        cout << '\n' << endl;

        // loeschen:
        for (int i = 0; i < zeichenbegrenzung; i++) {
            anfangsbuchstaben[i] = "\0";
            satz[i] = '\0';
        }

    }

    return 0;
}

