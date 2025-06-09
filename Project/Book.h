#pragma once

#include <string>
#include <iostream>

class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {
    }

    // cout의 << 연산자 override
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.title << " by " << book.author;
        return os;
    }
};