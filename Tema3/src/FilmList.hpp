#ifndef FILMLIST_HPP
#define FILMLIST_HPP

#include <cstddef>
#include <string>

class FilmList{
public:
    explicit FilmList(std::size_t size);

    FilmList(const FilmList& other);
    FilmList& operator=(const FilmList& other);

    ~FilmList();

    std::size_t size() const;
    std::string& operator[](std::size_t index);
    const std::string& operator[](std::size_t index) const;

private:
    std::size_t m_size;
    std::string* m_data;

    void swap(FilmList& other) noexcept;
};

#endif