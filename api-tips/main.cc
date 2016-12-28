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
#include "drafter.h"

#include "file_system.h"

int main(int argc, const char * argv[]) {
  mdp::ByteBuffer blueprint = haze::FileSystem::readApib("/tmp/get_user_info.apib");
  
  drafter_result *result = nullptr;
  int success = drafter_parse_blueprint(blueprint.c_str(), &result);
  
  drafter_options options;
  options.format = DRAFTER_SERIALIZE_JSON;
  char *drafter_json = drafter_serialize(result, options);
  std::string serialize_result = std::string(drafter_json);
  free(drafter_json);
  
  std::cout << "Parse success ? : " << (success == 0) << std::endl;
  std::cout << "Drafter JSON is : " << serialize_result << std::endl;
  
  return 0;
}

void try_snowcrash() {
  mdp::ByteBuffer blueprint = haze::FileSystem::readApib("/tmp/get_user_info.apib");
  
  snowcrash::ParseResult<snowcrash::Blueprint> ast;
  snowcrash::parse(blueprint, 0, ast);
  
  std::cout << "API Name: " << ast.node.description << std::endl;
  
  snowcrash::Elements &elements = ast.node.content.elements();
  for (int i = 0; i < elements.size(); i++) {
    snowcrash::Element::Category category = elements[i].category;
    if (category == snowcrash::Element::Category::DataStructureGroupCategory) {
      
    }
  }
}
