#include "HttpParser.h"

#include <string>

HttpParser::HttpParser(uint8_t* data, uint16_t size) :data(data), size(size) {
    
}

void HttpParser::parseHeaders() {
    uint8_t headerStart = 0;
    uint8_t headerEnd = 0;
    uint8_t numEndLine = 0;
    uint8_t tmpChar = *(data + headerEnd);

    // get method
    while(tmpChar != ' ') {
        headerEnd++;
        tmpChar = *(data + headerEnd);
    }

    this->values[std::string((char*) (data + headerStart), headerEnd - headerStart)] = 
        std::make_pair<uint16_t, uint16_t>(headerStart, headerEnd + 1);

    // go to start of headers
    while(tmpChar != '\n') {
        headerEnd++;
        tmpChar = *(data + headerEnd);
    }
    headerEnd++;

    // parse headers
    while(!this->headersDone) {

        while(tmpChar != ':') {
            headerEnd++;

            if(tmpChar == '\n') {
                numEndLine++;                
                headerStart = headerEnd;                
            } 

            if(numEndLine == 2) {
                this->headersDone = true;
                break;
            }                

            tmpChar = *(data + headerEnd);
        }
        
        if(!this->headersDone) {
            this->values[std::string((char*) (data + headerStart), headerEnd - headerStart)] = 
                std::make_pair<uint16_t, uint16_t>(headerStart, headerEnd + 1);
        }        
    }
}

bool HttpParser::hasHeader(std::string key) {
    if(this->headersDone) {
        parseHeaders();
    } 

    return this->values.contains(key);
}

bool HttpParser::isMethod(std::string method) {
    return this->hasHeader(method);
}

std::string HttpParser::getHeader(std::string key) {
    if(this->headersDone) {
        parseHeaders();
    } 

    std::pair<uint16_t, uint16_t>& range = this->values.at(key);

    return std::string(range.first, range.second - range.first);
}