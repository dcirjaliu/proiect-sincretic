#include<iostream>

using namespace std;

#define nr_regine 8

//variabile globale
int tabla_sah[nr_regine][nr_regine];
int v[nr_regine];  //vectorul care retine pozitiile reginelor

void initTabla()
{
    for(int i = 0; i < nr_regine; i++)
        for(int j = 0; j < nr_regine; j++)
            tabla_sah[i][j]=0;
}

//verifica daca plasarea reginei pe linia k este corecta
bool verificaPoz(int k)
{
    //parcurgem toate reginele deja plasate pe liniile anterioare
    for(int i = 0;i < k; i++)
         if (v[i] == v[k] || v[i] == v[k] + (k - i) || v[i] == v[k] - (k - i))  //daca reginele se ataca intre ele
            return false;
    
    return true;
}

bool solutieCompleta(int k)
{
    if(k == nr_regine-1)    //daca au fost plasate toate reginele
        return true;

    return false;
}

void Afisare()
{
    initTabla();

    for(int i = 0; i < nr_regine; i++)
    {
        for(int j = 0; j < nr_regine; j++)
        {
            if(j == v[i])   //verifica daca coloana curenta (j) este aceeasi cu coloana reginei plasate pe linia i
                tabla_sah[i][j] = 1;
            
            cout << tabla_sah[i][j] << " "; 
        }

        cout << endl;
    }

    cout << "-----------------------------\n";
}

void plaseazaRegine(int k)
{
    for(int i = 0; i < nr_regine; i++)
    {
        v[k] = i;   //plasam regina pe coloana i, pe linia k

        if(verificaPoz(k)) //verificam daca plasarea este valida
        {
            if(solutieCompleta(k))  //daca am plasat toate reginele, afisam tabla
                Afisare();
            else
                plaseazaRegine(k + 1);  //daca nu am plasat toate reginele, trecem la urmatoarea linia
        }
    }
} 

int main()
{
    plaseazaRegine(0);  //pornim de la linia 0

    return 0;
}