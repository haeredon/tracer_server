#include "CountGetsRule.h"
#include "Event.h"

#include <iostream>
#include <unordered_map>

CountGetsRule::CountGetsRule() {
    this->id = 1;
}

RuleEvent CountGetsRule::evaluate(ParserFactory& parserFactory) {    
     bool occured = parserFactory.getHttpParser().isMethod("GET");

     return RuleEvent { this->id, occured, 0, 0 };
}

