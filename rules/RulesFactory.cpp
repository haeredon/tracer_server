#include "RulesFactory.h"

const std::vector<AbstractRule>& RulesFactory::getRules(struct entity_t* entity) {
    const auto ret = new std::vector<AbstractRule>{};
    return *ret;
}