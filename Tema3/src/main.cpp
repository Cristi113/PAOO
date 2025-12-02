
#include <iostream>
#include <thread>
#include <mutex>
#include <memory>
#include <chrono>

#include "FilmList.hpp"

using namespace std;
using namespace std::chrono_literals;

void modificaFilmeSafe(shared_ptr<FilmList> listaPartajata, mutex& mtx, const string& numeThread){
    lock_guard<mutex> lock(mtx);

    cout << "[" << numeThread << "] START modificare (SYNC - cu mutex)" << endl;
    for (size_t i = 0; i < listaPartajata->size(); ++i){
        string& film = (*listaPartajata)[i];
        string original = film;
        film = "[" + numeThread + "] " + original;
        
        cout << "[" << numeThread << "] Modificat: " << original << " -> " << film << endl;
        this_thread::sleep_for(50ms);
        
        film = original;
    }
    cout << "[" << numeThread << "] END modificare (SYNC)" << endl << endl;
}

void modificaFilmeUnsafe(shared_ptr<FilmList> listaPartajata, const string& numeThread){
    
    cout << "[" << numeThread << "] START modificare (ASYNC - fara mutex, RISC!)" << endl;
    for (size_t i = 0; i < listaPartajata->size(); ++i){
        string& film = (*listaPartajata)[i];
        string original = film;
        
        film = "[" + numeThread + "] " + original;
        
        cout << "[" << numeThread << "] Modificat: " << original << " -> " << film << endl;
        this_thread::sleep_for(50ms);
    }
    cout << "[" << numeThread << "] END modificare (ASYNC)" << endl << endl;
}

int main()
{
    cout << "Demonstratie Effective C++ - Item 13 si Item 14 (Filme, thread-uri, smart pointers)" << endl;

    FilmList lista(3);
    lista[0] = "The Matrix";
    lista[1] = "Inception";
    lista[2] = "Interstellar";

    cout << "Lista initiala de filme:" << endl;
    for (size_t i = 0; i < lista.size(); ++i){
        cout << "  - " << lista[i] << endl;
    }

    FilmList listaCopie = lista;
    listaCopie[0] = "The Matrix Reloaded";

    cout << endl;
    cout << "Dupa copiere si modificarea copiei:" << endl;
    cout << "Original:" << endl;
    for (size_t i = 0; i < lista.size(); ++i){
        cout << "  - " << lista[i] << endl;
    }

    cout << "Copia:" << endl;
    for (size_t i = 0; i < listaCopie.size(); ++i){
        cout << "  - " << listaCopie[i] << endl;
    }

    FilmList altaLista(2);
    altaLista = lista;

    cout << endl;
    cout << "Alta lista (copiata prin operator= din original):" << endl;
    for (size_t i = 0; i < altaLista.size(); ++i){
        cout << "  - " << altaLista[i] << endl;
    }

    unique_ptr<FilmList> listaUnica(new FilmList(2));
    (*listaUnica)[0] = "Blade Runner 2049";
    (*listaUnica)[1] = "Dune";

    cout << endl;
    cout << "Lista detinuta de unique_ptr:" << endl;
    for (size_t i = 0; i < listaUnica->size(); ++i){
        cout << "  - " << (*listaUnica)[i] << endl;
    }

    shared_ptr<FilmList> sharedLista = std::move(listaUnica);

    cout << endl;
    cout << "Dupa mutarea in shared_ptr, listaUnica este " << (listaUnica ? "valida" : "nullptr") << endl;

    shared_ptr<FilmList> sharedLista2 = sharedLista;
    cout << "Numar de referinte la FilmList (shared_ptr.use_count()): " << sharedLista.use_count() << endl;

    cout << endl;
    cout << "=== Demonstratie SYNC: Modificare resursa partajata CU mutex ===" << endl;
    
    (*sharedLista)[0] = "Blade Runner 2049";
    (*sharedLista)[1] = "Dune";
    
    mutex mtx;

    thread t1(modificaFilmeSafe, sharedLista, ref(mtx), "T1-SYNC");
    thread t2(modificaFilmeSafe, sharedLista2, ref(mtx), "T2-SYNC");

    t1.join();
    t2.join();
    
    cout << "Lista dupa modificari SYNC (cu mutex, sigura):" << endl;
    for (size_t i = 0; i < sharedLista->size(); ++i) {
        cout << "  - " << (*sharedLista)[i] << endl;
    }

    cout << endl;
    cout << "=== Demonstratie ASYNC: Modificare resursa partajata FARA mutex ===" << endl;
    
    (*sharedLista)[0] = "Blade Runner 2049";
    (*sharedLista)[1] = "Dune";

    thread t3(modificaFilmeUnsafe, sharedLista, "T3-ASYNC");
    thread t4(modificaFilmeUnsafe, sharedLista2, "T4-ASYNC");

    t3.join();
    t4.join();
    
    cout << "Lista dupa modificari ASYNC (fara mutex) - poate fi corupta:" << endl;
    for (size_t i = 0; i < sharedLista->size(); ++i) {
        cout << "  - " << (*sharedLista)[i] << endl;
    }

    return 0;
}