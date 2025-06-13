// #ifndef BOOK_H
// #define BOOK_H

#pragma once
#include <string>

// Book 클래스 생성
class Book {
private:
    std::string title;
    std::string author;

public:
    // 생성자 -> 멤버 초기화 리스트
    Book(const std::string& title, const std::string& author);

    // getter
    std::string getTitle() const;
    std::string getAuthor() const;

    // setter
    void setTitle(const std::string& newTitle);
    void setAuthor(const std::string& newAuthor);
};

// #endif