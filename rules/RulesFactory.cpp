#include "RulesFactory.h"
#include "CountGetsRule.h"

RulesFactory::RulesFactory() {
    rules.try_emplace(1);
}

AbstractRule& RulesFactory::getRule(uint32_t ruleId) {
    return rules.at(ruleId);        
}