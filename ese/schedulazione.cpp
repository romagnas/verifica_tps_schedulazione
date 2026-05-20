#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Struttura per memorizzare i dati di un singolo processo
struct Processo 
{
    int id;
    int arrivo;
    int durata;
    int priorita;
};

void schedulaProcessiES1(vector<Processo> vettProcessi) 
{
    int tempo = 0;
    vector<Processo> coda;
    int finiti = 0;

    //svolgimento
    while (finiti < vettProcessi.size())
    {
        //controllo arrivo
        for (int i = 0; i < vettProcessi.size(); i++)
        {
            if (tempo == vettProcessi[i].arrivo)
            {
                if (coda.size() == 1)
                {
                    cout << "Entra processo " << coda[0].id << " a tempo 0" << endl;
                }
                coda.push_back(vettProcessi[i]);
            }
        }

        coda[0].durata--;
        tempo++;

        if (coda[0].durata == 0)
        {
            finiti++;
            cout << "Finisce processo " << coda[0].id << " a tempo " << tempo << endl;
            if (coda.size() > 1)
            {
                cout << "Entra processo " << coda[1].id << " a tempo " << tempo << endl;
            }
            coda.erase(coda.begin());
        }
    }
}

void schedulaProcessiES2(vector<Processo> vettProcessi) 
{   
    int finiti = 0;
    int tempo = 0;
    vector<Processo> coda;
    //SCRIVI QUI IL CODICE PER L'ESERCIZIO 2
    //ordinamento array
    if (coda.size() > 1)
    {
        for (int i = 0; i < coda.size(); i++)
        {
            for (int j = 0; j < coda.size() - i - 1; j++)
            {
                if (coda[i].priorita < coda[j].priorita && j != i)
                {
                    swap(coda[i], coda[j]);
                }
                else if (coda[i].priorita == coda[j].priorita && j != i)
                {
                    if (coda[i].durata > coda[j].durata)
                    {
                        swap(coda[i], coda[j]);
                    }
                }
            }
        }
    }


    //svolgimento
    while (finiti < vettProcessi.size())
    {
        //controllo arrivo
        for (int i = 0; i < vettProcessi.size(); i++)
        {
            if (tempo == vettProcessi[i].arrivo)
            {
                if (coda.size() == 1)
                {
                    cout << "Entra processo " << coda[0].id << " a tempo 0" << endl;
                }
                coda.push_back(vettProcessi[i]);
            }
        }

        coda[0].durata--;
        tempo++;

        if (coda[0].durata == 0)
        {
            finiti++;
            cout << "Finisce processo " << coda[0].id << " a tempo " << tempo << endl;
            if (coda.size() > 1)
            {
                cout << "Entra processo " << coda[1].id << " a tempo " << tempo << endl;
            }
            coda.erase(coda.begin());
        }
    }
    
}

int main()
{
    ifstream file("input.txt");
    
    // Controllo se il file esiste e si apre correttamente
    if (!file.is_open()) {
        cout << "Errore nell'apertura del file!" << endl;
        return 1;
    }

    int n;
    file >> n; // Legge il numero totale di processi dalla prima riga

    vector<Processo> vettProcessi(n);

    // Popola il vettore di processi
    for (int i = 0; i < n; i++) 
    {
        file >> vettProcessi[i].id 
             >> vettProcessi[i].arrivo 
             >> vettProcessi[i].durata 
             >> vettProcessi[i].priorita;
    }
    
    file.close();

    //Test esercizio 1
    //schedulaProcessiES1(vettProcessi);
    
    //Test esercizio 2
    schedulaProcessiES2(vettProcessi);
    return 0;
}