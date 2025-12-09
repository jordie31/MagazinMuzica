#ifndef PRODUCT_EXCEPTIONS_H
#define PRODUCT_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class ProductException : public std::runtime_error {
public:
    explicit ProductException(const std::string& msg)
        : std::runtime_error("ProductException: " + msg) {}
};

class InvalidPriceException : public ProductException {
public:
    explicit InvalidPriceException(float price)
        : ProductException("Invalid price: " + std::to_string(price)) {}
};

class InvalidStockException : public ProductException {
public:
    explicit InvalidStockException(int stock)
        : ProductException("Stock invalid: " + std::to_string(stock)) {}
};

class InvalidNameException : public ProductException {
public:
    explicit InvalidNameException(const std::string& name)
        : ProductException("Nume invalid: '" + name + "'") {}
};

class InvalidFormatException : public ProductException {
public:
    explicit InvalidFormatException(const std::string& format)
        : ProductException("Format media invalid: '" + format + "'") {}
};

class InvalidMaterialException : public ProductException {
public:
    explicit InvalidMaterialException(const std::string& material)
        : ProductException("Material instrumente invalid: '" + material + "'") {}
};

class InvalidPageCountException : public ProductException {
public:
    explicit InvalidPageCountException(int pages)
        : ProductException("Numar pagini invalid: " + std::to_string(pages)) {}
};

#endif // PRODUCT_EXCEPTIONS_H
