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

        // ���� ���
        stock = 3;
    }

    // cout�� << ������ override
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.title << " by " << book.author << " (" << book.stock << "�� ����)";
        return os;
    }
};