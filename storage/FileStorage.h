#ifndef TRACE_SERVER_STORAGE_FILE_STORAGE_H
#define TRACE_SERVER_STORAGE_FILE_STORAGE_H

#include <string>
#include <unordered_map>
#include <iostream>


class FileStorage {

    public:
                
        void write(std::string fileName, std::string data);

};

#endif // TRACE_SERVER_STORAGE_FILE_STORAGE_H