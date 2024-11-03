#ifndef TRACE_SERVER_STORAGE_FILE_STORE_H
#define TRACE_SERVER_STORAGE_FILE_STORE_H

#include <string>


class FileStore {

    private:

        std::string path;

    public:

        FileStore(std::string path);

        void open();

        void close();

        void write();

        void read();


}

#endif // TRACE_SERVER_STORAGE_FILE_STORE_H