#pragma once

#include "IBaseProject.h"

#include <iostream>

namespace baseproject {

class BaseProject : public IBaseProject {
 public:
  virtual void printMsg();
  virtual void checkDef();
};

}  // namespace baseproject
