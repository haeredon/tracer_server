#ifndef TRACE_SERVER_FILE_STORAGE_TRACER_DB_H
#define TRACE_SERVER_FILE_STORAGE_TRACER_DB_H

#include "Event.h"
#include "AbstractTracerDb.h"

#include <unordered_map>
#include <string>

template<class STORAGE_T>
class FileStorageTracerDb : AbstractTracerDb<STORAGE_T> {

    private:
        
        STORAGE_T db;

    public:

        FileStorageTracerDb(STORAGE_T&& db) : AbstractTracerDb<STORAGE_T>(std::forward<STORAGE_T>(db)) { }


        void saveRuleEvent(entity_t entity, RuleEvent&& ruleEvent) {
            std::string record = std::to_string(ruleEvent.timestamp)
                .append(",")
                .append(std::to_string(ruleEvent.ruleId))
                .append(",")
                .append((char*) ruleEvent.data, ruleEvent.dataSize);

            db.write("rule", record);
        }
        
        void saveNetworkPacket(time_t timestamp, entity_t entity, uint8_t* data, uint16_t size) {
            std::string record = std::to_string(timestamp)
                .append(",")
                .append(std::to_string(entity.entityId))
                .append(",")
                .append(std::to_string(entity.spanId))
                .append(",")
                .append((char*) data, size);
                
            db.write("networkTrace", record);
        }

};




#endif // TRACE_SERVER_FILE_STORAGE_TRACER_DB_H