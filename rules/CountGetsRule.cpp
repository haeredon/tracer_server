#include "CountGetsRule.h"

#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> CountGetsRule::evaluate(uint8_t* data, AbstractEventParser& parser) {
    std::unordered_map<std::string, std::string> kage;
    kage["kage"] = "mand";

    return kage;
}