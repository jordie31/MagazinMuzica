#include "Logger.h"

Logger::Logger(std::string fileName){
    this->fileName = fileName;
    logFile.open(fileName);
};

void Logger::log(std::string logMessage) {
    logFile.seekp (0, std::fstream::end);
    logFile << logMessage;
};



Logger::~Logger(){
    logFile.close();
}