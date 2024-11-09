#ifndef TRACE_SERVER_ENTITY_SERVICE_H
#define TRACE_SERVER_ENTITY_SERVICE_H

#include "rules/AbstractRule.h"
#include "rules/RulesFactory.h"
#include "Event.h"

#include <vector>

class EntityService {

    private:

        RulesFactory rulesFactory; 

    public:

        EntityService();

        std::vector<std::reference_wrapper<AbstractRule>> getEntityRules(entity_t entity, EVENT_TYPE eventType);

};


#endif // TRACE_SERVER_ENTITY_SERVICE_H



