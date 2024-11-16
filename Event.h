#ifndef TRACE_SERVER_EVENT_H
#define TRACE_SERVER_EVENT_H

#include <stdint.h>
#include <ctime>



enum class EVENT_TYPE {
    HTTP
};

struct entity_t {
    uint32_t entityId;
    uint32_t spanId;
};

struct event_t {
    struct entity_t entity;
    EVENT_TYPE type;
    uint16_t size;
    uint8_t data;
};

class RuleEvent {


    public:

        uint32_t ruleId;
        bool occured;
        time_t timestamp;

        uint8_t* data;
        uint16_t dataSize;

        RuleEvent(uint32_t ruleId, bool occured, time_t timestamp, uint8_t* data, uint16_t dataSize) : ruleId(ruleId), occured(occured), timestamp(timestamp), data(data), dataSize(dataSize) {

        }
};


#endif // TRACE_SERVER_EVENT_H