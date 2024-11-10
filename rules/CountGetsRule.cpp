#include "CountGetsRule.h"
#include "Event.h"

#include <iostream>
#include <unordered_map>


RuleEvent CountGetsRule::evaluate(AbstractEventParser& parser) {
     bool occured = parser.getValue("headers", "method") == "GET";

     return RuleEvent { this->id, occured, 0, 0 };
}

