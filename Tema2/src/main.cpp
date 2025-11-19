#include "Filme.hpp"

int main() {
    
    cout << "\n--- Item 10: Chaining assignments ---" << endl;
    Movie m1("The Matrix", 1999, 8.7, 1);
    Movie m2("Inception", 2010, 8.8, 1);
    Movie m3("Interstellar", 2014, 8.6, 1);
    
    m1.display();
    m2.display();
    m3.display();
    
    m1 = m2 = m3;
    m1.display();
    m2.display();
    m3.display();
    
    BadMovie bm2("Bad Movie 2", 2020, 5.0, 2);
    BadMovie bm3("Bad Movie 3", 2021, 4.5, 2);
    bm2 = bm3;
    
    cout << "\n--- Item 11: Self-assignment ---" << endl;
    m1.setTitle("The Dark Knight");
    m1.setYear(2008);
    m1.setRating(9.0);
    m1.display();
    m1 = m1;
    m1.display();
    
    BadMovie bm1("Bad Movie 1", 2019, 6.0, 2);
    bm1.display();
    bm1 = bm1;
    bm1.display();
    
    Movie* ptr1 = &m1;
    Movie* ptr2 = &m1;
    *ptr1 = *ptr2;
    
    cout << "\n--- Item 12: Copy all parts ---" << endl;
    Movie m4("Pulp Fiction", 1994, 8.9, 3);
    m4.display();
    m4 = m3;
    m4.display();
    cout << "m3.genreId = " << m3.getGenreId() << ", m4.genreId = " << m4.getGenreId() << endl;
    
    Movie m5(m1);
    m5.setTitle("Fight Club");
    m5.setYear(1999);
    m5.setRating(8.8);
    m5.display();
    cout << "m1.genreId = " << m1.getGenreId() << ", m5.genreId = " << m5.getGenreId() << endl;
    
    return 0;
}