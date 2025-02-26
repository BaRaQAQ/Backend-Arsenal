#include <iostream>
#include "book.h"

int main() {
    Library library;
    int choice;
    std::string title, author, ISBN;

    do {
        std::cout << "\n简易图书管理系统菜单：" << std::endl;
        std::cout << "1. 添加图书" << std::endl;
        std::cout << "2. 显示所有图书" << std::endl;
        std::cout << "3. 借阅图书" << std::endl;
        std::cout << "4. 归还图书" << std::endl;
        std::cout << "5. 退出系统" << std::endl;
        std::cout << "请输入你的选择：";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "请输入书名：";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "请输入作者：";
                std::getline(std::cin, author);
                std::cout << "请输入 ISBN：";
                std::cin >> ISBN;
                library.addBook(title, author, ISBN);
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                std::cout << "请输入要借阅的图书的 ISBN：";
                std::cin >> ISBN;
                library.borrowBook(ISBN);
                break;
            case 4:
                std::cout << "请输入要归还的图书的 ISBN：";
                std::cin >> ISBN;
                library.returnBook(ISBN);
                break;
            case 5:
                std::cout << "感谢使用图书管理系统，再见！" << std::endl;
                break;
            default:
                std::cout << "无效的选择，请重新输入。" << std::endl;
        }
    } while (choice != 5);

    return 0;
}