#pragma once

#include <string>
#include <iostream>

class Book {
public:
    typedef unsigned int BookID;

    BookID id;
    std::string title;
    std::string author;

    Book(BookID id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author) {
    }

    // cout의 << 연산자 override
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.title << " by " << book.author;
        return os;
    }
};
