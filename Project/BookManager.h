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
    // 책 추가 메서드
    virtual void addBook(const std::string& title, const std::string& author) override;

    // 책 검색 메서드
    virtual std::vector<BookQuery> findByTitle(const std::string& title) override;
    virtual std::vector<BookQuery> findByAuthor(const std::string& author) override;

    // 책 반입 반출 메서드
    virtual bool borrowBook(int index) override;
    virtual void returnBook(int index) override;
    virtual std::vector<BookQuery> GetBorrowedBooks() override;

    int GetStockByIndex(int index);

    // 모든 책 출력 메서드
    void displayAllBooks() const;

private:
    std::vector<Book> books; // 책 목록 저장
    std::unordered_map<Book::BookID, int> maxStocks; // 책 재고
    std::unordered_map<Book::BookID, int> currentStocks; // 책 재고
};