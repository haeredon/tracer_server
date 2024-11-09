#ifndef TRACE_SERVER_STORAGE_KEY_VALUE_DB_H
#define TRACE_SERVER_STORAGE_KEY_VALUE_DB_H

#include <string>
#include <unordered_map>
#include <iostream>

template<class KEY_T, class VAL_T>
class KeyValueDb {

    private:

        std::unordered_map<KEY_T, VAL_T> map;
    
    public: 

        void add(KEY_T key, VAL_T value) {
            map.insert(std::pair<KEY_T, VAL_T>(key, value));
        }

        void remove(const KEY_T key) {            
            map.erase(key);
        }

        const VAL_T& find(KEY_T key) {
            return *map.find(key);
        }

        void update(KEY_T key, VAL_T value) {
            printf("KeyValueDb::update(): Not implemented.\n");
            throw;
        }

};

#endif // TRACE_SERVER_STORAGE_KEY_VALUE_DB_H