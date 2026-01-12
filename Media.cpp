#include "Media.h"
#include "ProductExceptions.h"

// construcotr
Media::Media(const std::string &name, float price, int stock, const std::string &format)
    : Product(name, price, stock)
{
    if (format.empty())
        throw InvalidFormatException(format);

    this->format = format;
}

// functia de show
std::string Media::showDetails()  {
    return "ID: " + std::to_string(getID()) +
           " | Name: " + getName() +
           " | Price: " + std::to_string(getPrice()) +
           " | Stock: " + std::to_string(getStock()) +
           " | Format: " + format;
}

// destructor
Media::~Media() = default;

// getteri
std::string Media :: getType()   {
        return "Media";
    };

 //std::string& Media :: getFormat()  { return format; }

// clone
std::unique_ptr<Product> Media :: clone() const  {
        return std::make_unique<Media>(*this);
    };
