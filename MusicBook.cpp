#include "MusicBook.h"
#include "ProductExceptions.h"

MusicBook::MusicBook(const std::string &name, float price, int stock, int numberOfPages, const std::string &author)
    : Product(name, price, stock)
{
    if (numberOfPages <= 0)
        throw InvalidPageCountException(numberOfPages);

    if (author.empty())
        throw ProductException("Author cannot be empty");

    this->numberOfPages = numberOfPages;
    this->author = author;
}

MusicBook::~MusicBook() = default;

std::string MusicBook::showDetails() const {
    return "ID: " + std::to_string(getID()) +
           " | Name: " + getName() +
           " | Author: " + author +
           " | Number of Pages: " + std::to_string(numberOfPages) +
           " | Price: " + std::to_string(getPrice()) +
           " | Stock: " + std::to_string(getStock());
}
