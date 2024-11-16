#ifndef TRACE_SERVER_ABSTRACT_TRACER_DB_H
#define TRACE_SERVER_ABSTRACT_TRACER_DB_H

#include "Event.h"

#include <unordered_map>
#include <string>

template<class STORAGE_T>
class AbstractTracerDb {

    private:
        
        STORAGE_T db;

    public:

        AbstractTracerDb(STORAGE_T&& db) : db(std::forward<STORAGE_T>(db)) { }


        virtual void saveRuleEvent(entity_t entity, RuleEvent&& RuleEvent) = 0;
        
        virtual void saveNetworkPacket(time_t timestamp, entity_t entity, uint8_t* data, uint16_t size) = 0;

};




#endif // TRACE_SERVER_ABSTRACT_TRACER_DB_H