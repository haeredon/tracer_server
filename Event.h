#ifndef TRACE_SERVER_EVENT_H
#define TRACE_SERVER_EVENT_H

#include <stdint.h>




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
};


#endif // TRACE_SERVER_EVENT_H