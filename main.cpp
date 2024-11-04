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


int main(int argc, char* argv[]) {
  std::cout << "Tracer Server Starting" << std::endl;

  Receiver receiver {8080};

  receiver.initialize();
  receiver.addController(new EventController {});

  receiver.start();
  
  receiver.stop();
}         


