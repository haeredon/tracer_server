#include "CountGetsRule.h"

#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> CountGetsRule::evaluate(AbstractEventParser& parser) {
    std::string method = parser.getValue("headers", "method");

    std::unordered_map<std::string, std::string> ret; 

    if(method == "GET") {
        ret.insert({ "GET", "1" });
    }

    return ret;
}