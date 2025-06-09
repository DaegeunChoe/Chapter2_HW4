#include <vector>
#include <unordered_map>
#include <string>
#include "Book.h"

class IAddBook {
public:
    virtual void addBook(const std::string& title, const std::string& author) = 0;
};

struct BookQuery {
public:
    BookQuery(Book* book, int index) : book(book), index(index) {}
    Book* book;
    int index;
};

class IFindBook {
public:
    virtual std::vector<BookQuery> findByTitle(const std::string& title) = 0;
    virtual std::vector<BookQuery> findByAuthor(const std::string& author) = 0;
};

class IBorrowBook {
public:
    virtual bool borrowBook(int index) = 0;
    virtual void returnBook(int index) = 0;
    virtual std::vector<BookQuery> GetBorrowedBooks() = 0;
};

class BookManager : public IAddBook, public IFindBook, public IBorrowBook {
public:
    // å �߰� �޼���
    virtual void addBook(const std::string& title, const std::string& author) override;

    // å �˻� �޼���
    virtual std::vector<BookQuery> findByTitle(const std::string& title) override;
    virtual std::vector<BookQuery> findByAuthor(const std::string& author) override;

    // å ���� ���� �޼���
    virtual bool borrowBook(int index) override;
    virtual void returnBook(int index) override;
    virtual std::vector<BookQuery> GetBorrowedBooks() override;

    int GetStockByIndex(int index);

    // ��� å ��� �޼���
    void displayAllBooks() const;

private:
    std::vector<Book> books; // å ��� ����
    std::unordered_map<Book::BookID, int> maxStocks; // å ���
    std::unordered_map<Book::BookID, int> currentStocks; // å ���
};