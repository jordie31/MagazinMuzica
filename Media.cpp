#include "Media.h"
#include "ProductExceptions.h"

Media::Media(const std::string &name, float price, int stock, const std::string &format)
    : Product(name, price, stock)
{
    if (format.empty())
        throw InvalidFormatException(format);

    this->format = format;
}

std::string Media::showDetails() const {
    return "ID: " + std::to_string(getID()) +
           " | Name: " + getName() +
           " | Price: " + std::to_string(getPrice()) +
           " | Stock: " + std::to_string(getStock()) +
           " | Format: " + format;
}

Media::~Media() = default;
