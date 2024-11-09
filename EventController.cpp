#include "EventController.h"
#include "Event.h"

#include <iostream>
#include <unordered_map>

void EventController::handle(event_t* event) {
    // std::vector<std::reference_wrapper<AbstractRule>>&& entityRules = this->entityService.getEntityRules(event->entity, event->type);
    // std::unique_ptr<AbstractEventParser> parser = this->parserFactory.getParser(event->type);

    // uint8_t age[] = {3,4,5,6,7};
    
    // for(auto& rule : entityRules) {
    //     printf("Run rule\n");

    //     // std::unordered_map<std::string, std::string> ruleData = rule.get().evaluate(age, *parser);

    //     // save ruleData to memory

    // }
}