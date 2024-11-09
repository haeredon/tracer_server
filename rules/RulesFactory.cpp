#include "RulesFactory.h"
#include "CountGetsRule.h"

RulesFactory::RulesFactory() {
    CountGetsRule* rule = new CountGetsRule;
    std::reference_wrapper<AbstractRule> wrapper{*rule};

    rules.insert({ 1, wrapper });
}

std::reference_wrapper<AbstractRule> RulesFactory::getRule(uint32_t ruleId) {
    return rules.at(ruleId);        
}