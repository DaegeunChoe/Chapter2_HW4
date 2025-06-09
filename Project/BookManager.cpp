#include <iostream>
#include "BookManager.h"
#include "Book.h"

void BookManager::addBook(const std::string& title, const std::string& author) {
    Book::BookID newID = books.size();
    books.push_back(Book(newID, title, author)); // push_back ���
    currentStocks[newID] = 3;
    maxStocks[newID] = 3;
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
    Book::BookID id = books[index].id;
    if (currentStocks[id] > 0) {
        currentStocks[id] -= 1;
        return true;
    }
    else {
        return false;
    }
    return false;
}

void BookManager::returnBook(int index)
{
    Book::BookID id = books[index].id;
    if (currentStocks[id] < maxStocks[id]) {
        currentStocks[id] += 1;
    }
}

std::vector<BookQuery> BookManager::GetBorrowedBooks()
{
    std::vector<BookQuery> result;
    for (int n = 0; n < books.size(); n++)
    {
        Book::BookID id = books[n].id;
        if (currentStocks[id] < maxStocks[id]) {
            result.emplace_back(&books[n], n);
        }
    }
    return result;
}

int BookManager::GetStockByIndex(int index)
{
    return currentStocks[books[index].id];
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
