#pragma once

#include <iostream>

#ifdef WIN32
#ifdef SUBPROJECT_EXPORTS
#define SUBPROJECT_API __declspec(dllexport)
#else
#define SUBPROJECT_API __declspec(dllimport)
#endif
#else
#define SUBPROJECT_API
#endif

namespace subproject {

class SubProject {
 public:
  SUBPROJECT_API void printMsg();
  SUBPROJECT_API void checkDef();
};

}  // namespace subproject

extern "C" {
SUBPROJECT_API subproject::SubProject* CreateSubProject();
SUBPROJECT_API void DestroySubProject(subproject::SubProject* obj);
}
