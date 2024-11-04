#include "parsers/AbstractEventParser.h"
#include "ParserFactory.h"
#include "HttpParser.h"
#include "Event.h"

#include <memory>


std::unique_ptr<AbstractEventParser> ParserFactory::getParser(EVENT_TYPE eventType) {
    

    if(eventType == EVENT_TYPE::HTTP) {
        return std::make_unique<HttpParser>();
    }

    throw;
}