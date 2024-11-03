#ifndef TRACE_SERVER_EVENT_CONTROLLER_H
#define TRACE_SERVER_EVENT_CONTROLLER_H

#include "AbstractController.h"
#include "parsers/AbstractEventParser.h"
#include "Event.h"

#include <cstdint>
#include <unordered_map>

class EventController : public AbstractController {

    public:

        void handle(event_t* data);

}


#endif // TRACE_SERVER_EVENT_CONTROLLER_H