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
#include "FileStorageTracerDb.h"
#include "EntityService.h"
#include "parsers/ParserFactory.h"
#include "storage/FileStorage.h"


int main(int argc, char* argv[]) {
  std::cout << "Tracer Server Starting" << std::endl;

  Receiver receiver {8080};
  
  auto fileStorage = new FileStorage{ };
  FileStorageTracerDb<FileStorage> tracerDb { std::move(*fileStorage) };
  EntityService entityService;

  auto controller = new EventController<FileStorageTracerDb<FileStorage>, EntityService> {
    tracerDb, entityService
  };

  receiver.initialize();
  receiver.addController(controller);

  receiver.start();

  receiver.stop();
}         


