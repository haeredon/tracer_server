#ifndef TRACE_SERVER_PARSERS_HTTP_PARSER_H
#define TRACE_SERVER_PARSERS_HTTP_PARSER_H

#include "AbstractController.h"

#include <cstdint>

class HttpParser {

    public:

        void parse(uint8_t* data);


}


#endif // TRACE_SERVER_PARSERS_HTTP_PARSER_H