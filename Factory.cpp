
#include "Factory.h"
#include <memory>

std::unique_ptr<Product> Factory::createInstrument(
                    const std::string &name, float price, int stock, const std::string &material) {

    return std::make_unique<Instrument>(name, price, stock, material);
}

std::unique_ptr<Product> Factory::createMedia(
                    const std::string &name, float price, int stock, const std::string &format) {

    return std::make_unique<Media>(name, price, stock, format);
}

std::unique_ptr<Product> Factory::createMusicBook(
                    const std::string &name, float price, int stock, int numberOfPages, const std::string &author) {

    return std::make_unique<MusicBook>(name, price, stock, numberOfPages, author);
}