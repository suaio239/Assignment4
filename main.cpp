#include <iostream>
#include <regex>
#include <windows.h>
#include "Manager/BookManager.h"
#include "Manager/BorrowManager.h"
#include "util/Validation.h"

int main() {
    SetConsoleOutputCP(65001);

    std::cout << "프로그램을 시작하려면 Enter 키를 누르세요.." << std::endl;
    std::cin.get();

    BookManager manager;
    BorrowManager borrower;

    // 책 추가 테스트 데이터 확인
    // manager.addBook("테스트", "test");
    // manager.addBook("테스트2", "test");

    while (true) {
        std::cout << "\n도서관 관리 프로그램" << std::endl;
        std::cout << "1. 책 추가" << std::endl
                 << "2. 모든 책 출력" << std::endl
                 << "3. 책 찾기" << std::endl
                 << "4. 책 폐기" << std::endl
                 << "5. 책 대여" << std::endl
                 << "6. 책 반납" << std::endl
                 << "7. 재고 출력" << std::endl
                 << "8. 종료" << std::endl
                 << "선택: ";

        std::string input;
        std::getline(std::cin, input);

        if (!Validation::isInRange(input, 1, 8)) {
            std::cout << "1~8 사이의 숫자만 입력해주세요." << std::endl;
            continue;
        }

        // if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
        //     std::cout << "잘못된 입력입니다. 1~8 사이의 숫자만 입력해주세요." << std::endl;
        //     continue;
        // }

        int choice = std::stoi(input);
        std::string title, author;

        switch (choice) {
            case 1: {
                while (true) {
                    std::cout << "책 제목: ";
                    std::getline(std::cin, title);
                    if (Validation::isNotEmptyOrWhiteSpace(title)) break;
                        std::cout << "제목은 비어 있을 수 없습니다." << std::endl;
                }

                while (true) {
                    std::cout << "책 저자: ";
                    std::getline(std::cin, author);
                    if (Validation::isValidAuthorName(author)) break;
                    std::cout << "저자 이름은 한글, 영문, 공백만 허용됩니다." << std::endl;
                }

                manager.addBook(title, author);
                borrower.initializeStock(manager);
                break;
            }
            case 2:
                manager.displayAllBooks();
                break;
            case 3: {
                std::cout << "검색 시 원하는 방법을 선택해주세요."<< std::endl
                        << "1. 책 제목으로 검색" << std::endl
                        << "2. 저자명으로 검색" << std::endl
                        << "선택: ";

                std::string select;
                std::getline(std::cin, select);

                if (!Validation::isInRange(select, 1, 2)) {
                    std::cout << "1 또는 2만 입력해주세요." << std::endl;
                    break;
                }

                int choose = std::stoi(select);

                if (choose == 1) {
                    std::cout << "검색할 책 제목: ";
                    std::getline(std::cin, title);
                    manager.searchBookByTitle(title);
                    break;

                }else if(choose == 2){
                    std::cout << "검색할 저자명: ";
                    std::getline(std::cin, author);
                    manager.searchBookByAuthor(author);
                    break;
                }else {
                    std::cout << "잘못된 입력입니다.";
                    break;
                }

            }
            case 4: {
                std::cout << "페기할 책 제목: ";
                std::getline(std::cin, title);
                manager.removeBookByTitle(title);
                borrower.initializeStock(manager);
                break;
            }
            case 5: {
                std::cout << "대여할 책 제목: ";
                std::getline(std::cin, title);
                borrower.borrowBook(title);
                break;
            }
            case 6: {
                std::cout << "반납할 책 제목: ";
                std::getline(std::cin, title);
                borrower.returnBook(title);
                break;
            }
            case 7:
                borrower.displayStock();
                break;
            case 8:
                std::cout << "프로그램을 종료합니다." << std::endl;
                return 0;
            default:
                std::cout << "잘못된 입력입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}