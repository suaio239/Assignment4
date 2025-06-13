//
// Created by suaio on 2025-06-13.
//

// #ifndef BORROWMANAGER_H
// #define BORROWMANAGER_H

#pragma once
#include <string>
#include <unordered_map>

#include "BookManager.h"

// BorrowManager 클래스 (책 재고, 대여 관리)
class BorrowManager {
    private:
        // key : title, value : quantity
        std::pmr::unordered_map<std::string, int> stock;

    public:
        // 책 재고 3권 초기화
        void initializeStock(BookManager& bm, int quantity = 3);

        // 책 대여가능 확인 by title
        bool isAvailable(const std::string& title);

        // 책 대여기능 확인 by author
        bool isAvailableByAuthor(const BookManager& bm, const std::string& author);

        // 책 대여 by title
        void borrowBook(const std::string& title);

        // 책 대여 by author
        void borrowBookByAuthor(const BookManager& bm, const std::string& author);

        // 책 반환
        void returnBook(const std::string& title);

        // 현재 재고 출력
        void displayStock();
};



// #endif //BORROWMANAGER_H
