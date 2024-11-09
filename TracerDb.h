#ifndef TRACE_SERVER_TRACER_DB_H
#define TRACE_SERVER_TRACER_DB_H

#include "Event.h"

#include <unordered_map>
#include <string>

template<class STORAGE_T>
class TracerDb {

    private:
        
        STORAGE_T db;

    public:

        TracerDb(STORAGE_T&& db) : db(std::forward<STORAGE_T>(db)) { }


        void saveRuleEvent(entity_t entity, uint32_t ruleId, std::unordered_map<std::string, std::string>&& data) {
            
        }
        

};




#endif // TRACE_SERVER_TRACER_DB_H