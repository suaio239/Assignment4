#include "Book/Book.h"

Book::Book(const std::string& title, const std::string& author)
    : title(title), author(author) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}