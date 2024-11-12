// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "stdlib.h"

#include "config.h"
#include "Receiver.h"
#include "EventController.h"
#include "TracerDb.h"
#include "EntityService.h"
#include "parsers/ParserFactory.h"
#include "storage/KeyValueDb.h"


int main(int argc, char* argv[]) {
  std::cout << "Tracer Server Starting" << std::endl;

  Receiver receiver {8080};
  
  auto keyValueStore = new KeyValueDb<std::string, std::string>;
  TracerDb<KeyValueDb<std::string, std::string>> tracerDb { std::move(*keyValueStore) };
  EntityService entityService;

  auto controller = new EventController<TracerDb<KeyValueDb<std::string, std::string>>, EntityService> {
    tracerDb, entityService
  };

  receiver.initialize();
  receiver.addController(controller);

  receiver.start();

  receiver.stop();
}         


