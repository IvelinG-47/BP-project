#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const int MAX_ABONATI = 30;
const int MAX_RAZGOVORI = 101
;

struct Abonat
{
    char dogovor[9];
    int srok = 0;
    char ime[50] = { 0 };
    char telefon[11] = { 0 };
    int razgovori[MAX_RAZGOVORI] = { 0 };
    double cenaMin = 0.0;
    double mesecTaksa = 0.0;
    int broiRazgovori = 0;
};

Abonat abonati[MAX_ABONATI];
int broiAbonati = 0;



void bubbleTaksa()
{
    for (int i = 0; i < broiAbonati - 1; i++)
    {
        for (int j = 0; j < broiAbonati - 1; j++)
        {
            if (abonati[j].mesecTaksa > abonati[j + 1].mesecTaksa)
            {
                Abonat temp = abonati[j];
                abonati[j] = abonati[j + 1];
                abonati[j + 1] = temp;
            }
        }
    }
}

void bubbleIme(Abonat arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (strcmp(arr[j].ime, arr[j + 1].ime) > 0)
            {
                Abonat temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



void dobaviAbonati()
{

    int n;
    cout << "Kolko abonata da dobavq? " << endl;
    cin >> n;

    system("cls");

    if (broiAbonati + n > MAX_ABONATI)
    {
        cout << "Nqma mqsto za tolkova abonati." << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        Abonat a;
        cout << "Dogovor (BG******) 6 simvola : " << endl;

        do
        {
            cin >> a.dogovor;
            cout << endl;
            if (strlen(a.dogovor) < 8)
            {
                cout << "opitai pak" << endl;

            }
        } while (strlen(a.dogovor) < 8);


        cout << "Srok (1 ili 2): " << endl;

        do
        {
            cin >> a.srok;
            if (a.srok != 1 && a.srok != 2)
            {
                cout << "opitai pak" << endl;
            }

        } while (a.srok != 1 && a.srok != 2);

        cout << "Ime: " << endl;
        cin.ignore();
        cin.getline(a.ime, 50);
        cout << endl;

        cout << "Telefon (10 cifri): " << endl;
        do
        {
            cin >> a.telefon;
            cout << endl;
            if (strlen(a.telefon) < 8)
            {
                cout << "opitai pak" << endl;

            }
        } while (strlen(a.dogovor) < 8);

        cout << "Cena na minuta: " << endl;
        cin >> a.cenaMin;
        cout << endl;
        cout << "Mesecna taksa: " << endl;
        cin >> a.mesecTaksa;

        a.broiRazgovori = 0;
        for (int j = 0; j < MAX_RAZGOVORI; j++)
        {
            a.razgovori[j] = 0;
        }

        abonati[broiAbonati++] = a;
        cout << endl;
        cout << "abonatut e dobaven uspeshno" << endl;
        system("pause");
        system("cls");
    }
}

void pokazhiVsichki()
{

    if (broiAbonati != 0)
    {
        system("cls");
        for (int i = 0; i < broiAbonati; i++)
        {

            cout << endl << "Abonat " << i + 1 << ":" << endl;
            cout << "Dogovor: " << abonati[i].dogovor << endl;
            cout << "Srok: " << abonati[i].srok << endl;
            cout << "Ime: " << abonati[i].ime << endl;
            cout << "Telefon: " << abonati[i].telefon << endl;
            cout << "Cena/min: " << abonati[i].cenaMin << endl;
            cout << "Taksa: " << abonati[i].mesecTaksa << endl;
            cout << "Broi razgovori: " << abonati[i].broiRazgovori << endl;
            cout << endl;
            cout << endl;

        }
    }
    else
    {
        cout << "Nqma abonati" << endl;
    }

    system("pause");
    system("cls");

}

void tursiTelefon()
{
    if (broiAbonati != 0)
    {
        char t[11];
        cout << "Telefon: " << endl;
        cin >> t;

        for (int i = 0; i < broiAbonati; i++) {
            if (strcmp(abonati[i].telefon, t) == 0)
            {

                cout << "Nameren: " << abonati[i].ime << endl;
                system("pause");
                return;
            }

        }
        cout << "Nqma takuv abonat." << endl;

    }
    else
    {
        cout << "Nqma abonati." << endl;

    }
    system("pause");
    system("cls");

}

void naiVisokaCena()
{
    if (broiAbonati != 0)
    {
        double maxCena = 0.0;
        int maxSub = 0;
        for (int i = 0; i < broiAbonati; i++)
        {
            if (abonati[i].cenaMin > maxCena)
            {
                maxCena = abonati[i].cenaMin;
                maxSub = i;
            }

        }
        cout << abonati[maxSub].ime << " - " << abonati[maxSub].cenaMin << endl;
    }
    else
    {
        cout << "Nqma abonati." << endl;
    }

    system("pause");
    system("cls");
}

void sortiraneTaksa()
{
    bubbleTaksa();
    cout << "Podrezhdaneto e gotovo." << endl;
    system("pause");
    system("cls");
}

int zapisFile()
{
    fstream f("TextFile1.txt", ios::binary | ios::out);
    for (size_t i = 0; i < broiAbonati; i++)
    {
        f.write((char*)&abonati[i], sizeof(Abonat));
    }

    f.close();
    cout << "Zapazeno." << endl;
    system("pause");
    exit(0);

}

void chetiFile()
{
    fstream f("TextFile1.txt", ios::binary | ios::in);
    if (!f.is_open())
    {
        cout << "Faila ne se otvarq." << endl;
        exit(1);
    }
    else
    {
        while (f.read((char*)&abonati[broiAbonati], sizeof(Abonat)))
        {
            broiAbonati++;
        };
        f.close();
    }

}

void dvugodishni()
{
    if (broiAbonati != 0)
    {
        Abonat dog2[MAX_ABONATI];
        int k = 0;

        for (int i = 0; i < broiAbonati; i++)
        {
            if (abonati[i].srok == 2)
                dog2[k++] = abonati[i];
        }


        bubbleIme(dog2, k);

        for (int i = 0; i < k; i++)
            cout << dog2[i].ime << " - " << dog2[i].telefon << endl;
    }
    else
    {
        cout << "Nqma abonati." << endl;
    }

    system("pause");
    system("cls");
}

void tursiSrokTaksa()
{
    if (broiAbonati != 0)
    {
        int srok;
        double minTaksa;
        cout << "Srok: " << endl;
        cin >> srok;
        cout << "Min taksa: " << endl;
        cin >> minTaksa;

        for (int i = 0; i < broiAbonati; i++)
        {
            if (abonati[i].srok == srok && abonati[i].mesecTaksa > minTaksa)
            {
                cout << abonati[i].ime << " - " << abonati[i].mesecTaksa << endl;
                system("pause");
                system("cls");
                return;
            }

        }
        cout << "Nqma takuv abonat." << endl;
    }
    else
    {
        cout << "Nqma abonati." << endl;
    }
    system("pause");
    system("cls");

}

void generiraneRazgovori()
{
    if (broiAbonati != 0)
    {
        for (int i = 0; i < broiAbonati; i++)
        {
            if (abonati[i].broiRazgovori == 0)
            {
                int br = rand() % 100 + 1;
                abonati[i].broiRazgovori = br;
                for (int j = 0; j < br; j++)
                {
                    abonati[i].razgovori[j] = rand() % 3600 + 30;
                }

            }

        }
        cout << "Razgovorite sa generirani." << endl;
    }
    else
    {
        cout << "Nqma abonati." << endl;
    }

    system("pause");
    system("cls");
}

void plashtane()
{
    if (broiAbonati != 0)
    {
        char t[11];
        cout << "Telefon: " << endl;
        cin >> t;

        for (int i = 0; i < broiAbonati; i++)
        {
            if (strcmp(abonati[i].telefon, t) == 0)
            {

                double suma = abonati[i].mesecTaksa;

                for (int j = 0; j < abonati[i].broiRazgovori; j++)
                {
                    int sec = abonati[i].razgovori[j];
                    int min = (sec + 59) / 60;
                    suma = suma + (min * abonati[i].cenaMin);
                }

                cout << "Smetka: " << suma << " lv" << endl;
                cout << "Shte platite li? (1=da, 0=ne): " << endl;

                int otg2;
                cin >> otg2;

                if (otg2 == 1)
                {
                    cout << "Uspeshno platena." << endl;
                    abonati[i].broiRazgovori = 0;
                    for (int j = 0; j < MAX_RAZGOVORI; j++)
                    {
                        abonati[i].razgovori[j] = 0;
                    }

                }
                else
                {
                    cout << "Srok do 1-vi sledvasht mesec." << endl;
                }
            }
            else
            {
                cout << "Nqma abonati." << endl;
            }

            system("pause");
            system("cls");
            return;
        }
    }

    cout << "Nqma takuv abonat." << endl;
    system("pause");
    system("cls");
}



void submenu()
{
    system("cls");
    int otg;
    do {
        cout << endl << "--- PODMENU ---" << endl;
        cout << "1. Dvugodishni podredeni po ime" << endl;
        cout << "2. Tursene po srok i taksa" << endl;
        cout << "0. Nazad" << endl;
        cout << endl;
        cout << endl;
        cout << "Vuvedete vashiqt izbor- ";
        cin >> otg;

        switch (otg)
        {
        case 1: dvugodishni(); break;
        case 2: tursiSrokTaksa(); break;
        case 0: break;
        default: cout << "Nevaliden izbor." << endl; break;
        }


    } while (otg != 0);
    system("cls");
}

int main()
{
    chetiFile();

    int otg;
    do {

        cout << endl << "---- MENU ----" << endl;
        cout << "1. Dobavqne" << endl;
        cout << "2. Pokazvane" << endl;
        cout << "3. Tursene po telefon" << endl;
        cout << "4. Nai-visoka cena na minuta" << endl;
        cout << "5. Podrejdane po taksa" << endl;
        cout << "6. Podmenyu" << endl;
        cout << "7. Generirane na razgovori" << endl;
        cout << "8. Plashtane na smetka" << endl;
        cout << "0. Izhod" << endl;
        cout << endl;
        cout << endl;
        cout << "Vuvedete vashiqt izbor- ";
        cin >> otg;
        cout << endl;

        switch (otg)
        {
        case 1: dobaviAbonati(); break;
        case 2: pokazhiVsichki(); break;
        case 3: tursiTelefon(); break;
        case 4: naiVisokaCena(); break;
        case 5: sortiraneTaksa(); break;
        case 6: submenu(); break;
        case 7: generiraneRazgovori(); break;
        case 8: plashtane(); break;
        case 0: zapisFile();break;
        default: cout << "Nevaliden izbor." << endl; system("pause"); break;
        }
        system("cls");
    } while (otg != 0);



}
