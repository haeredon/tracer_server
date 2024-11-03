#include "EventController.h"
#include "Event.h"

void EventController::handle(event_t* data) {
    // parse event

    // get entity id

    // get entity rules for event type and appliccation

    // run rules on data. no need to optimize for now. return type should be some internal event data object. not the Event class

    // save it to storage    
}


void EventController::addParser(AbstractEventParser* parser) {
    this->parsers.insert(std::make_pair<EVENT_TYPE, AbstractEventParser*>(,))
}