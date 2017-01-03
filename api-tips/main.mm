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

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
  mdp::ByteBuffer blueprint = haze::FileSystem::readApib("/Users/FrankLin/Documents/Xcode/gago/api-tips/api-tips/test_data/get_user_info.apib");
  
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
