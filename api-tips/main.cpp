//
//  main.cpp
//  api-tips
//
//  Created by Frank Lin on 27/12/2016.
//  Copyright © 2016 Frank Lin. All rights reserved.
//

#include <iostream>

#include "snowcrash.h"
#include "ByteBuffer.h"

int main(int argc, const char * argv[]) {
  mdp::ByteBuffer blueprint = R"(
# My API
## GET /message
  + Response 200 (text/plain)
  
  Hello World!
  )";
  
  snowcrash::ParseResult<snowcrash::Blueprint> ast;
  snowcrash::parse(blueprint, 0, ast);
  
  std::cout << "API Name: " << ast.node.name << std::endl;
  return 0;
}
