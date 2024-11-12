
#include "ParserFactory.h"
#include "HttpParser.h"
#include "Event.h"

#include <memory>

ParserFactory::ParserFactory(uint8_t* data, uint16_t size) : data(data), size(size), httpParser(nullptr) {

}

HttpParser& ParserFactory::getHttpParser() {
    if(httpParser == nullptr) {
        httpParser = new HttpParser{this->data, this->size};
    }
    return *httpParser;    
}