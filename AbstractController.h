#ifndef TRACE_SERVER_ABSTRACT_CONTROLLER_H
#define TRACE_SERVER_ABSTRACT_CONTROLLER_H

#include "Event.h"

#include <cstdint>

class AbstractController {

    public:

        virtual void handle(event_t* data) = 0;


};


#endif // TRACE_SERVER_ABSTRACT_CONTROLLER_H