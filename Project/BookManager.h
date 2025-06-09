#include <vector>
#include <string>

class Book;

class BookManager {
private:
    std::vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    void addBook(const std::string& title, const std::string& author);

    // ��� å ��� �޼���
    void displayAllBooks() const;
};