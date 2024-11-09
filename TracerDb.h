#ifndef TRACE_SERVER_TRACER_DB_H
#define TRACE_SERVER_TRACER_DB_H

#include "Event.h"

#include <unordered_map>
#include <string>

class TracerDb {

    private:
        
        

    public:

        void saveRuleEvent(entity_t entity, uint32_t ruleId, std::unordered_map<std::string, std::string>&& data);

};




#endif // TRACE_SERVER_TRACER_DB_H