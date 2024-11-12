#ifndef TRACE_SERVER_PARSERS_PARSER_FACTORY_H
#define TRACE_SERVER_PARSERS_PARSER_FACTORY_H

#include "Event.h"
#include "HttpParser.h"

#include <memory>
#include <cstdint>
#include <vector>
#include <unordered_map>

class ParserFactory {

    private:

        uint8_t* data;
        uint16_t size;

        HttpParser* httpParser;

    public:

        ParserFactory(uint8_t* data, uint16_t size);

        HttpParser& getHttpParser();

};


#endif // TRACE_SERVER_PARSERS_PARSER_FACTORY_H