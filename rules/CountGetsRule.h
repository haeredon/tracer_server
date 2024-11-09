#ifndef TRACE_SERVER_RULES_COUNT_GETS_RULE_H
#define TRACE_SERVER_RULES_COUNT_GETS_RULE_H

#include "parsers/AbstractEventParser.h"
#include "AbstractRule.h"

#include <unordered_map>
#include <string>
#include <cstdint>

class CountGetsRule : public AbstractRule {

    public:

        std::unordered_map<std::string, std::string> evaluate(AbstractEventParser& parser);

};


#endif // TRACE_SERVER_RULES_COUNT_GETS_RULE_H