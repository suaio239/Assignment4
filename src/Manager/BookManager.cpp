#include "Manager/BookManager.h"

#include <algorithm>
#include <iostream>

// 책 추가 메서드
void BookManager::addBook(const std::string& title, const std::string& author) {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            std::cout << "이미 같은 제목의 책이 등록되어 있습니다." << std::endl;
            return;
        }
    }

    // push_back (객체 복사 후 생성) -> emplace_back (복사 없이 객체 직접 생성)
    books.emplace_back(title, author);
    std::cout << "요청하신 책이 추가되었습니다.";
}

// 책 제거 메서드
void BookManager::removeBookByTitle( const std::string& title) {
    books.erase(std::remove_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getTitle() == title;
    }), books.end());
    std::cout << "요청한 " << title << " 책이 폐기되었습니다.";
}

// 전체 잭 출력 메서드
void BookManager::displayAllBooks() const {
    if (books.empty()) {
        std::cout << "현재 등록된 책이 없습니다." << std::endl;
        return;
    }

    std::cout << "도서 목록:" << std::endl;
    for (const auto& book : books) {
        std::cout << "- " << book.getTitle() << " - 저자: " << book.getAuthor() << std::endl;
    }
}

// 책 제목 검색 메서드
void BookManager::searchBookByTitle(const std::string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            std::cout << "책을 찾았습니다." << std::endl
                    << book.getTitle() << " - 저자: " << book.getAuthor() << std::endl;
            return;
        }
    }
    std::cout << "검색하신 책 제목을 찾을 수 없습니다." << std::endl;
}

// 책 제목 검색 메서드
void BookManager::searchBookByAuthor(const std::string& author) const {
    bool check = false;

    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            if (!check) {
                std::cout << "저자 '" << author << "'의 책 리스트:" << std::endl;
                check = true;
            }
                std::cout << book.getTitle() << std::endl;
        }
    }

    if (!check) {
        std::cout << "해당 저자의 책을 찾을 수 없습니다." << std::endl;
    }
}

// getAllBooks 정의 추가 (참조반환)
const std::vector<Book>& BookManager::getAllBooks() const {
    return books;
}
