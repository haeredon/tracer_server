#ifndef TRACE_SERVER_RULES_ABSTRACT_RULE_H
#define TRACE_SERVER_RULES_ABSTRACT_RULE_H

#include "Event.h"
#include "parsers/AbstractEventParser.h"

#include <cstdint>
#include <unordered_map> 
#include <string>

class AbstractRule {

    protected:

        uint32_t id;

    public:

        virtual RuleEvent evaluate(AbstractEventParser& parser) = 0;

};


#endif // TRACE_SERVER_RULES_ABSTRACT_RULE_H