#include "Logger.h"

Logger::Logger(std::string fileName){
    this->fileName = fileName;
    logFile.open(fileName,std::ios::app);
    // std::ios::app e ca sa imi puna file pointerul la finalul fisierului
};

void Logger::log(std::string logMessage) {
    logFile << logMessage << std :: endl;
};



Logger::~Logger(){
    logFile.close();
}