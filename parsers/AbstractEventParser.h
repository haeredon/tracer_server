#ifndef TRACE_SERVER_PARSERS_ABSTRACT_EVENT_PARSER_H
#define TRACE_SERVER_PARSERS_ABSTRACT_EVENT_PARSER_H

#include "AbstractController.h"

#include <cstdint>

class AbstractEventParser {

    public:

        virtual void parse(uint8_t* data) = 0;


}


#endif // TRACE_SERVER_PARSERS_ABSTRACT_EVENT_PARSER_H