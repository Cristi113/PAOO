#include "Filme.hpp"

FilmInfo::FilmInfo(int id) : genreId(id) {}

FilmInfo::~FilmInfo() {}

FilmInfo& FilmInfo::operator=(const FilmInfo& rhs){
    if(this != &rhs){
        genreId = rhs.genreId;
    }
    return *this;
}

BadMovie::BadMovie(const string& t, int y, double r, int gid) : FilmInfo(gid), title(new string(t)), year(y), rating(r){
    cout << "BadMovie constructor: " << t << " (" << y << ")" << endl;
}

BadMovie::BadMovie(const BadMovie& other) : FilmInfo(other), title(new string(*other.title)), year(other.year), rating(other.rating){
    cout << "BadMovie copy constructor: " << *title << endl;
}

BadMovie::~BadMovie(){
    cout << "BadMovie destructor: " << (title ? *title : "null") << endl;
    delete title;
}

void BadMovie::operator=(const BadMovie& rhs){
    delete title;
    title = new string(*rhs.title);
    year = rhs.year;
    rating = rhs.rating;
    FilmInfo::operator=(rhs);
    cout << "BadMovie assignment (UNSAFE): " << *title << endl;
}

string BadMovie::getTitle() const{
    return title ? *title : "";
}

int BadMovie::getYear() const{
    return year;
}

double BadMovie::getRating() const{
    return rating;
}

void BadMovie::display() const{
    cout << "BadMovie: " << (title ? *title : "null") << " (" << year << ") - Rating: " << rating << ", Genre ID: " << genreId << endl;
}

Movie::Movie(const string& t, int y, double r, int gid) : FilmInfo(gid), title(new string(t)), year(y), rating(r){
    cout << "Movie constructor: " << t << " (" << y << ")" << endl;
}

Movie::Movie(const Movie& other) : FilmInfo(other), title(new string(*other.title)), year(other.year), rating(other.rating){
    cout << "Movie copy constructor: " << *title << endl;
}

Movie::~Movie(){
    cout << "Movie destructor: " << (title ? *title : "null") << endl;
    delete title;
}

Movie& Movie::operator=(const Movie& rhs){
    if(this == &rhs){
        cout << "Self-assignment detected! Skipping..." << endl;
        return *this;
    }
    
    FilmInfo::operator=(rhs);
    
    delete title;
    title = new string(*rhs.title);
    year = rhs.year;
    rating = rhs.rating;
    
    cout << "Assignment operator: " << *title << endl;
    return *this;
}

string Movie::getTitle() const{
    return title ? *title : "";
}

void Movie::setTitle(const string& t){
    if (title) *title = t; 
    else title = new string(t);
}

int Movie::getYear() const{
    return year;
}

void Movie::setYear(int y){
    year = y;
}

double Movie::getRating() const{
    return rating;
}

void Movie::setRating(double r){
    rating = r;
}

void Movie::display() const{
    cout << "Movie: " << (title ? *title : "null") << " (" << year << ") - Rating: " << rating << ", Genre ID: " << genreId << endl;
}