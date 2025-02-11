#ifndef TRACE_SERVER_RULES_RULES_FACTORY_H
#define TRACE_SERVER_RULES_RULES_FACTORY_H

#include "Event.h"
#include "AbstractRule.h"

#include <cstdint>
#include <vector>
#include <unordered_map>

class RulesFactory {

    private:

        std::unordered_map<uint32_t, std::reference_wrapper<AbstractRule>> rules;

    public:

        RulesFactory();

        std::reference_wrapper<AbstractRule> getRule(uint32_t ruleId);

};


#endif // TRACE_SERVER_RULES_RULES_FACTORY_H