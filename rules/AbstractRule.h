#ifndef TRACE_SERVER_RULES_ABSTRACT_RULE_H
#define TRACE_SERVER_RULES_ABSTRACT_RULE_H

#include "Event.h"
#include "parsers/AbstractEventParser.h"

#include <cstdint>
#include <unordered_map> 
#include <string>

class AbstractRule {

    public:

        std::unordered_map<std::string, std::string> evaluate(uint8_t* data, AbstractEventParser& parser);

};


#endif // TRACE_SERVER_RULES_ABSTRACT_RULE_H