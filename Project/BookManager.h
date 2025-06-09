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
    std::vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    virtual void addBook(const std::string& title, const std::string& author) override;

    // 책 검색 메서드
    virtual std::vector<Book*> findByTitle(const std::string& title);
    virtual std::vector<Book*> findByAuthor(const std::string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;
};