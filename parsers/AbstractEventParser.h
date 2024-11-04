#ifndef TRACE_SERVER_PARSERS_ABSTRACT_EVENT_PARSER_H
#define TRACE_SERVER_PARSERS_ABSTRACT_EVENT_PARSER_H

#include <cstdint>
#include <unordered_map>
#include <string>

class AbstractEventParser {

    public:

        virtual std::string getValue(std::string parseSpace, std::string key) = 0;


};


#endif // TRACE_SERVER_PARSERS_ABSTRACT_EVENT_PARSER_H