#pragma once

#include <iostream>

#ifdef WIN32
#ifdef BASEPROJECT_EXPORTS
#define BASEPROJECT_API __declspec(dllexport)
#else
#define BASEPROJECT_API __declspec(dllimport)
#endif
#else
#define BASEPROJECT_API
#endif

namespace baseproject {

class BaseProject {
 public:
  BASEPROJECT_API void printMsg();
  BASEPROJECT_API void checkDef();
};

}  // namespace baseproject

extern "C" {
BASEPROJECT_API baseproject::BaseProject* CreateBaseProject();
BASEPROJECT_API void DestroyBaseProject(baseproject::BaseProject* obj);
}
