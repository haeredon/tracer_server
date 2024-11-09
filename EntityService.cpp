#include "EntityService.h"


EntityService::EntityService() {
    
}


std::vector<std::reference_wrapper<AbstractRule>> EntityService::getEntityRules(entity_t entity, EVENT_TYPE eventType) {
    std::vector<std::reference_wrapper<AbstractRule>> rules;

    if(entity.entityId == 1 && eventType == EVENT_TYPE::HTTP) {
        rules.push_back(rulesFactory.getRule(1));
    }

    return rules;
}

