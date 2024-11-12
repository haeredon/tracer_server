#ifndef TRACE_SERVER_PARSERS_HTTP_PARSER_H
#define TRACE_SERVER_PARSERS_HTTP_PARSER_H


#include <cstdint>
#include <unordered_map>
#include <string>

class HttpParser {

    private:


        uint8_t* data;
        uint16_t size;

        std::unordered_map<std::string, std::pair<uint16_t, uint16_t>> values;

        bool headersDone = false;

        void parseHeaders();

    public:

        HttpParser(uint8_t* data, uint16_t size);

        bool hasHeader(std::string key);

        std::string getHeader(std::string key);

        bool isMethod(std::string);

};


#endif // TRACE_SERVER_PARSERS_HTTP_PARSER_H