#include <vector>
#include <string>
#include "Book.h"

class IAddBook {
public:
    virtual void addBook(const std::string& title, const std::string& author) = 0;
};

class IFindBook {
public:
    virtual std::vector<Book*> findByTitle(const std::string& title) = 0;
    virtual std::vector<Book*> findByAuthor(const std::string& author) = 0;
};

class BookManager : public IAddBook, public IFindBook{
private:
    std::vector<Book> books; // å ��� ����

public:
    // å �߰� �޼���
    virtual void addBook(const std::string& title, const std::string& author) override;

    // å �˻� �޼���
    virtual std::vector<Book*> findByTitle(const std::string& title);
    virtual std::vector<Book*> findByAuthor(const std::string& author);

    // ��� å ��� �޼���
    void displayAllBooks() const;
};