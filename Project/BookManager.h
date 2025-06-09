#include <vector>
#include <string>

class Book;

class BookManager {
private:
    std::vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const std::string& title, const std::string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;
};