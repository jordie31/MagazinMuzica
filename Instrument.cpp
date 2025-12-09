#include "Instrument.h"
#include "ProductExceptions.h"

Instrument::Instrument(const std::string &name, float price, int stock, const std::string &material)
    : Product(name, price, stock)
{
    if (material.empty())
        throw InvalidMaterialException(material);

    this->material = material;
}

Instrument::~Instrument() = default;

std::string Instrument::showDetails() const {
    return "ID: " + std::to_string(getID()) +
           " | Name: " + getName() +
           " | Material: " + material +
           " | Price: " + std::to_string(getPrice()) +
           " | Stock: " + std::to_string(getStock());
}
