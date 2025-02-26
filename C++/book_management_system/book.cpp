#include <iostream>
#include "book.h"

// 添加图书
void Library::addBook(const std::string& title, const std::string& author, const std::string& ISBN) {
    books.emplace_back(title, author, ISBN);
    std::cout << "图书添加成功！" << std::endl;
}

// 显示所有图书
void Library::displayBooks() const {
    if (books.empty()) {
        std::cout << "图书馆暂无图书。" << std::endl;
        return;
    }

    std::cout << "图书馆所有图书信息如下：" << std::endl;
    for (const auto& book : books) {
        std::cout << "书名：" << book.title << ", 作者：" << book.author
                  << ", ISBN：" << book.ISBN << ", 借阅状态："
                  << (book.isBorrowed ? "已借出" : "可借阅") << std::endl;
    }
}

// 根据 ISBN 查找图书
Book* Library::findBookByISBN(const std::string& ISBN) {
    for (auto& book : books) {
        if (book.ISBN == ISBN) {
            return &book;
        }
    }
    return nullptr;
}

// 借阅图书
bool Library::borrowBook(const std::string& ISBN) {
    Book* book = findBookByISBN(ISBN);
    if (book) {
        if (!book->isBorrowed) {
            book->isBorrowed = true;
            std::cout << "图书借阅成功！" << std::endl;
            return true;
        } else {
            std::cout << "该图书已被借出。" << std::endl;
        }
    } else {
        std::cout << "未找到该图书。" << std::endl;
    }
    return false;
}

// 归还图书
bool Library::returnBook(const std::string& ISBN) {
    Book* book = findBookByISBN(ISBN);
    if (book) {
        if (book->isBorrowed) {
            book->isBorrowed = false;
            std::cout << "图书归还成功！" << std::endl;
            return true;
        } else {
            std::cout << "该图书未被借出，无需归还。" << std::endl;
        }
    } else {
        std::cout << "未找到该图书。" << std::endl;
    }
    return false;
}