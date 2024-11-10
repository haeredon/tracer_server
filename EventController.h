#ifndef TRACE_SERVER_EVENT_CONTROLLER_H
#define TRACE_SERVER_EVENT_CONTROLLER_H

#include "AbstractController.h"
#include "parsers/AbstractEventParser.h"
#include "parsers/ParserFactory.h"
#include "EntityService.h"
#include "Event.h"
#include "TracerDb.h"

#include <cstdint>
#include <unordered_map>

template<class STORAGE_T, class ENTITY_SERVICE_T, class PARSERFACTORY_T>
class EventController : public AbstractController {

    private: 

        STORAGE_T& db;
        ENTITY_SERVICE_T& entityService;
        PARSERFACTORY_T& parserFactory;

    public:

        EventController(STORAGE_T& db,
        ENTITY_SERVICE_T& entityService,
        PARSERFACTORY_T& parserFactory) : db(db), entityService(entityService), parserFactory(parserFactory) {}

        void handle(event_t* event) {
            std::vector<std::reference_wrapper<AbstractRule>>&& entityRules = this->entityService.getEntityRules(event->entity, event->type);
            std::unique_ptr<AbstractEventParser> parser = this->parserFactory.getParser(event->type, &event->data, event->size);
           

            for(auto& rule : entityRules) {
                printf("Run rule\n");


                RuleEvent ruleEvent = rule.get().evaluate(*parser);

                

        }
}

};


#endif // TRACE_SERVER_EVENT_CONTROLLER_H
