#ifndef TRACE_SERVER_PARSERS_PARSER_FACTORY_H
#define TRACE_SERVER_PARSERS_PARSER_FACTORY_H

#include "Event.h"
#include "AbstractEventParser.h"

#include <memory>
#include <cstdint>
#include <vector>
#include <unordered_map>

class ParserFactory {

    public:

        std::unique_ptr<AbstractEventParser> getParser(EVENT_TYPE eventType, uint8_t* data, uint16_t size);

};


#endif // TRACE_SERVER_PARSERS_PARSER_FACTORY_H