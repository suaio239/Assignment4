// #ifndef BOOKMANAGER_H
// #define BOOKMANAGER_H

#pragma once
#include <vector>
#include "Book/Book.h"

// BookManager 클래스 (Book 객체 관리)
class BookManager {
private:
    // Book 객체들을 관리하기 위한 동적배열
    std::vector<Book> books;

public:
    // 책 추가 메서드
    void addBook(const std::string& title, const std::string& author);

    // 책 제거 메서드
    void removeBookByTitle(const std::string& title);

    // 전체 책 출력 메서드
    void displayAllBooks() const;

    // 책 제목 검색 메서드
    void searchBookByTitle(const std::string& title) const;

    // 책 저자 검색 메서드
    void searchBookByAuthor(const std::string& author) const;

    // BookManager가 가지고 있는 책 목록
    const std::vector<Book>& getAllBooks() const;
};

// #endif