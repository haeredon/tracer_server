#ifndef TRACE_SERVER_RULES_RULES_FACTORY_H
#define TRACE_SERVER_RULES_RULES_FACTORY_H

#include "Event.h"
#include "AbstractRule.h"

#include <cstdint>
#include <vector>

class RulesFactory {

    public:

        const std::vector<AbstractRule>& getRules(struct entity_t* entity);

};


#endif // TRACE_SERVER_RULES_RULES_FACTORY_H