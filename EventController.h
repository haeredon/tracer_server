#ifndef TRACE_SERVER_EVENT_CONTROLLER_H
#define TRACE_SERVER_EVENT_CONTROLLER_H

#include "AbstractController.h"
#include "EntityService.h"
#include "Event.h"
#include "TracerDb.h"

#include <cstdint>
#include <unordered_map>

template<class STORAGE_T, class ENTITY_SERVICE_T>
class EventController : public AbstractController {

    private: 

        STORAGE_T& db;
        ENTITY_SERVICE_T& entityService;

    public:

        EventController(STORAGE_T& db,
        ENTITY_SERVICE_T& entityService) : db(db), entityService(entityService) {}

        void handle(event_t* event) {
            std::vector<std::reference_wrapper<AbstractRule>>&& entityRules = this->entityService.getEntityRules(event->entity, event->type);
            ParserFactory parserFactory{&event->data, event->size};

            for(auto& rule : entityRules) {
                printf("Run rule\n");

                RuleEvent ruleEvent = rule.get().evaluate(parserFactory);
                db.saveRuleEvent(event->entity, std::move(ruleEvent));                
            }

            db.saveNetworkPacket(event->entity, &event->data, event->size);
        }   

};


#endif // TRACE_SERVER_EVENT_CONTROLLER_H
