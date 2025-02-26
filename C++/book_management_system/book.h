#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

// 定义图书结构体
struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool isBorrowed;

    Book(const std::string& t, const std::string& a, const std::string& isbn)
        : title(t), author(a), ISBN(isbn), isBorrowed(false) {}
};

// 定义图书管理系统类
class Library {
private:
    std::vector<Book> books;

public:
    // 添加图书
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN);
    // 显示所有图书
    void displayBooks() const;
    // 根据 ISBN 查找图书
    Book* findBookByISBN(const std::string& ISBN);
    // 借阅图书
    bool borrowBook(const std::string& ISBN);
    // 归还图书
    bool returnBook(const std::string& ISBN);
};

#endif