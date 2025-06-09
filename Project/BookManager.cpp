#include <iostream>
#include "BookManager.h"
#include "Book.h"

void BookManager::addBook(const std::string& title, const std::string& author) {
    books.push_back(Book(books.size(), title, author)); // push_back ���
    std::cout << "å�� �߰��Ǿ����ϴ�: " << books.back() << std::endl;
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
        std::cout << "���� ��ϵ� å�� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "���� ���� ���:" << std::endl;
    for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
        std::cout << "- " << books[i] << std::endl;
    }
}
