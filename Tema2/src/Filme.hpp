#ifndef FILME_HPP
#define FILME_HPP

#include <string>
#include <iostream>
using namespace std;

class FilmInfo{
protected:
    int genreId;
public:
    FilmInfo(int id = 0);
    ~FilmInfo();
    
    FilmInfo& operator=(const FilmInfo& rhs);
    
    int getGenreId() const { return genreId; }
    void setGenreId(int id) { genreId = id; }
};

class BadMovie : public FilmInfo{
private:
    string* title;
    int year;
    double rating;
    
public:
    BadMovie(const string& t = "", int y = 0, double r = 0.0, int gid = 0);
    BadMovie(const BadMovie& other);
    ~BadMovie();
    
    void operator=(const BadMovie& rhs);
    
    string getTitle() const;
    int getYear() const;
    double getRating() const;
    void display() const;
};

class Movie : public FilmInfo{
private:
    string* title;
    int year;
    double rating;
    
public:
    Movie(const string& t = "", int y = 0, double r = 0.0, int gid = 0);
    Movie(const Movie& other);
    ~Movie();
    
    Movie& operator=(const Movie& rhs);
    
    string getTitle() const;
    void setTitle(const string& t);
    int getYear() const;
    void setYear(int y);
    double getRating() const;
    void setRating(double r);
    void display() const;
};

#endif