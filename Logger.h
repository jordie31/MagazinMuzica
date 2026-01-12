#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <iostream>
#include <fstream>

class Logger{
    std :: ofstream logFile;
    std :: string  fileName ;

public:
    Logger(std::string fileName);
    void log(std::string logMessage);
    ~Logger();
};


#endif