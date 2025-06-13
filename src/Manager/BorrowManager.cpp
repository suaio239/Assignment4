//
// Created by suaio on 2025-06-13.
//

#include "Manager/BorrowManager.h"
#include <iostream>

// 책 재고 3권 초기화
// 책을 추가할 때 마다 재고 초기화가 일어나 불명확한 재고 처리를 위해 중복 처리 예방
void BorrowManager::initializeStock(BookManager& bm, int quantity) {
    for (const auto& book : bm.getAllBooks()) {
        const std::string& title = book.getTitle();
        if (stock.find(title) == stock.end()) {
            stock[title] = quantity;
        }
    }
}

// 책 대여가능 확인 by title
bool BorrowManager::isAvailable(const std::string& title) {
    return stock.count(title) && stock[title] > 0;
}

// 책 대여가능 확인 by author
bool BorrowManager::isAvailableByAuthor(const BookManager& bm, const std::string& author) {
    std::vector<Book> books = bm.getAllBooks();
    for (const auto& book : books) {
        if (book.getAuthor() == author) {
            return isAvailable(book.getTitle());
        }
    }
    return false;
}

// 책 대여 by title
void BorrowManager::borrowBook(const std::string& title) {
    if (isAvailable(title)) {
        stock[title]--;
        std::cout << "대여 성공: " << title << std::endl;
    } else {
        std::cout << "대여 실패: 재고 없음" << std::endl;
    }
}

// 책 대여 by author
void BorrowManager::borrowBookByAuthor(const BookManager& bm, const std::string& author) {
    for (const auto& book : bm.getAllBooks()) {
        if (book.getAuthor() == author && isAvailable(book.getTitle())) {
            stock[book.getTitle()]--;
            std::cout << "대여 성공: " << book.getTitle() << std::endl;
            return;
        }
    }
    std::cout << "대여 실패: 작가 '" << author << "'의 책 재고 없음" << std::endl;
}

// 책 반환
void BorrowManager::returnBook(const std::string& title) {
    if (stock.count(title)) {
        stock[title]++;
        std::cout << "반납 완료: " << title << std::endl;
    } else {
        std::cout << "반납 실패: 책 정보 없음" << std::endl;
    }
}

// 재고 출력
void BorrowManager::displayStock() {
    std::cout << "\n📚 현재 책 재고:" << std::endl;
    for (auto& pair : stock) {
        std::cout << "제목: " << pair.first << ", 재고: " << pair.second << std::endl;
    }
}