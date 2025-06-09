#include <iostream>
#include "BookManager.h"
#include "Book.h"

void BookManager::addBook(const std::string& title, const std::string& author)
{
    books.push_back(Book(title, author)); // push_back ���
    std::cout << "å�� �߰��Ǿ����ϴ�: " << books.back() << std::endl;
}

void BookManager::displayAllBooks() const
{
    if (books.empty()) {
        std::cout << "���� ��ϵ� å�� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "���� ���� ���:" << std::endl;
    for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
        std::cout << "- " << books[i] << std::endl;
    }
}
