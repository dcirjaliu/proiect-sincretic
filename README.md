# Documentatie Tehnica - Proiect Sincretic MAP 2024 - 2025


## Motivarea si scopul proiectului

### Motivarea
Acest proiect este realizat a fost realizat ca parte a cursului Metode Avansate de Programare, la Universitatea Politehnica Timisoara, specializarea Informatica.

### Scopul
Scopul principal al proiectului a fost de a demonstra implementarea algoritmului pentru rezolvarea problemei celor **8 regine**. Aceasta este o problema clasica de algoritmica, ce implica gasirea tuturor pozitiilor valide pentru plasarea a 8 regine pe o tabla de sah, astfel incat niciuna sa nu se atace reciproc.

## Detalii de implementare

Proiectul a fost implementat folosind limbajul **C++**, iar algoritmul principal este **backtracking**, care cauta solutii valide prin explorarea tuturor posibilitatilor de plasare a reginelor pe tabla de sah.

### Structura codului

- **main.cpp** - acest fisier contine implementarea algoritumului de backtracking pentru problema reginelor

- **Fisier .gitignore** - listeaza fisierele si directoarele care nu trebuie incluse

- **Dockerfile** - descrie cum este construit mediul de rulare al aplicatiei intr-un container Docker (imaginea de baza utilizata si comenzile pentru compilare si rulare)

- **Fiser .yml pentru CI/CD** - automatizeaza procesul de testare, build si deployment

### Explicatie Functionalitati

1. **Initializarea tablei de sah (initTabla)**
    - Functia **initTabla** initializeaza tabla de sah cu dimensiunea de 8x8 (sau definita prin **nr_regine**), atribuind fiecarei celule valoarea **0**, ceea ce indica absenta reginelor.

2. **Verificarea pozitiei valide pentru regine (verificaPoz)**
    - Functia **verificaPoz** verifica daca plasarea unei regine pe o linie **k** este valida. O pozitie este considerata **valida** daca:
        - Nu exista alta regina pe aceeasi coloana.
        - Nu exista alta regina pe aceeasi diagonala, ascendenta sau descendenta.
    
3. **Verificarea solutiei complete (solutieCompleta)**
    - Functia **solutieCompleta** determina daca toate cele 8 regine au fost plasate fara sa se atace reciproc. Aceasta returneaza **true** daca ultima regina a fost plasata.

4. **Afisarea solutiei (Afisare)**
    - Functia **Afisare** marcheaza pozitiile reginelor pe tabla de sah folosind matricea **tabla_sah**. O valoare **1** indica prezenta unei regine, iar solutia este afisata pe ecran sub forma unei matrice 8x8. Dupa fiecare solutie, se afiseaza un separator.

5. **Plasarea reginelor pe tabla (plaseazaRegine)**
    - Aceasta este functia principala care implementeaza algoritmul de backtracking. Functia: 
        - Parcurge fiecare coloana **(i)** pe linia curenta **(k)**.
        - Plaseaza temporar regina pe pozitia **(k, i)**.
        - Verifica daca plasarea este valida cu functia **verificaPoz**.
        - Daca pozitia este valida:
            - Verifica daca solutia este completa folosind **solutieCompleta**.
            - Daca nu este completa, continua cautarea solutiilor pentru liniile urmatoare.

6. **Functia principala (main)**
    - Functia **main** initiaza procesul de rezolvare apeland functia **plaseazaRegine** pentru linia **0**.

### Tehnologii Folosite

- **Limbaj de programare**:
    - **C++** - folosit pentru logica si implementarea algoritumului.

- **Gestionarea mediului de rulare**:
    - **Docker** - pentru crearea unui container portabil si reproductibil al aplicatiei.

- **Controlul versiunilor**:
    - **Git** - pentru gestionarea istoriei proiectului.

- **Automatizare CI/CD**:
    - **Github Actions** - pentru integrarea continua si livrarea codului.

- **Editor de cod**:
    - **Visual Studio Code** - pentru scrierea si testarea codului.

- **Biblioteci standard C++**:
    - **<iostream>** - pentru input/output.

## Mediul de Dezvoltare

- **Sistem de operare**:
    - **Windows 10**

- **Editor/IDE**:
    - **Visual Studio Code**

- **Compilator**:
    - **gcc (GNU Compiler Colection)**

- **Containerizare**:
    - **Docker**

- **Control versiuni**:
    - **Git**

## Bibliografie

1. **Curs Tehnici de Programare** - Materiale oferite de Universitatea Politehnica Timisoara, 2023-2024. Rezolvarea **problemei celor N regine**.

2. **Curs Metode Avansate de Programare** - Exemple si materiale despre **Dockerfile** si **CI/CD**. Universitatea Politehnica Timisoara, 2024-2025.

3. **GitHub *.gitignore* Templates** - Exemple publice de fisiere **.gitignore**. Disponibile la: https://github.com/github/gitignore .

4. **ChatGPT** - Asistenta pentru generarea si optimizarea fisierului **.gitignore**.

## Exemple de Rulare

### Rulare intr-un container Docker
    - Construirea imaginii docker: docker build -t myapp .
    - Rularea containerului: docker run myapp

### Tragerea imaginii Docker din GitHub Container Registry
    - docker pull ghcr.io/dcirjaliu/proiect-sincretic/map-project:latest