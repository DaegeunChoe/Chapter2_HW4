#include <iostream>
#include "BookManager.h"
#include "Book.h"

void BookManager::addBook(const std::string& title, const std::string& author)
{
    books.push_back(Book(title, author)); // push_back 사용
    std::cout << "책이 추가되었습니다: " << books.back() << std::endl;
}

void BookManager::displayAllBooks() const
{
    if (books.empty()) {
        std::cout << "현재 등록된 책이 없습니다." << std::endl;
        return;
    }

    std::cout << "현재 도서 목록:" << std::endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        std::cout << "- " << books[i] << std::endl;
    }
}
