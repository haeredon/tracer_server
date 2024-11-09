#ifndef TRACE_SERVER_PARSERS_HTTP_PARSER_H
#define TRACE_SERVER_PARSERS_HTTP_PARSER_H

#include "AbstractEventParser.h"

#include <cstdint>
#include <unordered_map>
#include <string>

class HttpParser : public AbstractEventParser {

    private:

        std::unordered_map<std::string, std::string> values;

    public:

        HttpParser(uint8_t* data, uint16_t size);

        std::string getValue(std::string parseSpace, std::string key);


};


#endif // TRACE_SERVER_PARSERS_HTTP_PARSER_H