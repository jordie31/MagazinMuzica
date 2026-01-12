#include "Instrument.h"
#include "ProductExceptions.h"

// constructor
Instrument::Instrument(const std::string &name, float price, int stock, const std::string &material)
    : Product(name, price, stock)
{
    if (material.empty())
        throw InvalidMaterialException(material);

    this->material = material;
}

// destructor
Instrument::~Instrument() = default;

// functia de show
std::string Instrument::showDetails()  {
    return "ID: " + std::to_string(getID()) +
           " | Name: " + getName() +
           " | Material: " + material +
           " | Price: " + std::to_string(getPrice()) +
           " | Stock: " + std::to_string(getStock());
}

// clone
std::unique_ptr<Product> Instrument :: clone() const  {
        return std::make_unique<Instrument>(*this);
    };

// getter
 std::string& Instrument :: getMaterial()  { return material; }

std::string Instrument :: getType()   {
        return "Instrument";
    }