#include "HttpParser.h"
#include "AbstractEventParser.h"

#include <string>

HttpParser::HttpParser(uint8_t* data, uint16_t size) : AbstractEventParser(data, size) {
    
}

std::string HttpParser::getValue(std::string parseSpace, std::string key) {
    auto ret = this->values.find(key);

    if(ret != this->values.end()) {
        return (*ret).second;
    }

    for (uint16_t i = dataOffset ; i < size ; i++) {
                
    }
}