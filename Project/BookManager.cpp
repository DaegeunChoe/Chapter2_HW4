#include <iostream>
#include "BookManager.h"
#include "Book.h"

void BookManager::addBook(const std::string& title, const std::string& author) {
    books.push_back(Book(books.size(), title, author)); // push_back 사용
    std::cout << "책이 추가되었습니다: " << books.back() << std::endl;
}

std::vector<BookQuery> BookManager::findByTitle(const std::string& query) {
    std::vector<BookQuery> result;
    for (int n = 0; n < books.size(); n++)
    {
        if (books[n].title.find(query) != std::string::npos) {
            result.emplace_back(&books[n], n);
        }
    }
    return result;
}

std::vector<BookQuery> BookManager::findByAuthor(const std::string& query) {
    std::vector<BookQuery> result;
    for (int n = 0; n < books.size(); n++)
    {
        if (books[n].author.find(query) != std::string::npos) {
            result.emplace_back(&books[n], n);
        }
    }
    return result;
}

bool BookManager::borrowBook(int index)
{
    //if (books[index].stock > 0) {
    //    books[index].stock--;
    //    return true;
    //}
    //else {
    //    return false;
    //}
    return false;
}

void BookManager::returnBook(int index)
{
}

void BookManager::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "현재 등록된 책이 없습니다." << std::endl;
        return;
    }

    std::cout << "현재 도서 목록:" << std::endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        std::cout << "- " << books[i] << std::endl;
    }
}
