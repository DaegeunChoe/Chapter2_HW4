#pragma once

#include <string>
#include <iostream>

class Book {
public:
    std::string title;
    std::string author;
    int stock;

    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {

        // 남은 재고
        stock = 3;
    }

    // cout의 << 연산자 override
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.title << " by " << book.author << " (" << book.stock << "권 남음)";
        return os;
    }
};