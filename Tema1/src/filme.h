#include <iostream>
#include <string>
using namespace std;

class Film{
    private:
        string titlu;
        int* ratinguri;
        int nrRatinguri;

    public:
        Film(string t, int nr);
        ~Film();
        Film(const Film& f);
        Film(Film&& f) noexcept;

        void setRating(int i, int val);
        void afiseaza() const;

        const string& getTitlu() const {return titlu;}
};