#include "FilmList.hpp"

#include <algorithm>

using namespace std;

FilmList::FilmList(size_t size)
    : m_size(size),
      m_data(new string[size])
{

}

FilmList::FilmList(const FilmList& other)
    : m_size(other.m_size),
      m_data(new string[other.m_size])
{
    copy(other.m_data, other.m_data + other.m_size, m_data);
}

FilmList& FilmList::operator=(const FilmList& other){
    if (this != &other) {
        FilmList temp(other);
        swap(temp);
    }
    return *this;
}

FilmList::~FilmList(){
    delete[] m_data;
}

size_t FilmList::size() const{
    return m_size;
}

string& FilmList::operator[](size_t index){
    return m_data[index];
}

const string& FilmList::operator[](size_t index) const{
    return m_data[index];
}

void FilmList::swap(FilmList& other) noexcept{
    std::swap(m_size, other.m_size);
    std::swap(m_data, other.m_data);
}