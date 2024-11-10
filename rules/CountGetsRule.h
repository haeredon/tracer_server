#ifndef TRACE_SERVER_RULES_COUNT_GETS_RULE_H
#define TRACE_SERVER_RULES_COUNT_GETS_RULE_H

#include "parsers/AbstractEventParser.h"
#include "AbstractRule.h"

#include <unordered_map>
#include <string>
#include <cstdint>

class CountGetsRule : public AbstractRule {

    public:

        RuleEvent evaluate(AbstractEventParser& parser) override;

};


#endif // TRACE_SERVER_RULES_COUNT_GETS_RULE_H