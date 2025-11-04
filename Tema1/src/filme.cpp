#include "filme.h"

Film::Film(string t, int nr) : titlu(t), nrRatinguri(nr), ratinguri(nullptr){
    cout << "Constructor Film: " << titlu << endl;

    if(nrRatinguri > 0){
        ratinguri = new int[nrRatinguri];
        for(int i = 0; i < nrRatinguri; i++){
            ratinguri[i] = 0;
        }
    }
}

Film::~Film(){
    cout << "Destructor Film: " << titlu << endl;
    delete[] ratinguri;
}

Film::Film(const Film& f) : titlu(f.titlu), nrRatinguri(f.nrRatinguri), ratinguri(nullptr){
    cout << "Copy constructor Film: " << titlu << endl;

    if(nrRatinguri > 0){
        ratinguri = new int[nrRatinguri];
        for(int i = 0; i < nrRatinguri; i++){
            ratinguri[i] = f.ratinguri[i];
        }
    }
}

Film::Film(Film&& f) noexcept : titlu(std::move(f.titlu)), nrRatinguri(f.nrRatinguri), ratinguri(f.ratinguri){
    cout << "Move constructor Film: " << titlu << endl;

    f.ratinguri = nullptr;
    f.nrRatinguri = 0;
}

void Film::setRating(int i, int val){
    if(i >= 0 && i < nrRatinguri){
        ratinguri[i] = val;
    }
}

void Film::afiseaza() const{
    cout << "Film: " << titlu << " | Ratinguri: ";
    for (int i = 0; i < nrRatinguri; i++){
        cout << ratinguri[i] << " ";
    }
    cout << endl;
}