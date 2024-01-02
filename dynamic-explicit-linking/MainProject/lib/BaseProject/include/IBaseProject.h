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

class IBaseProject {
 public:
  virtual ~IBaseProject() {}
  virtual void printMsg() = 0;
  virtual void checkDef() = 0;
};

}  // namespace baseproject

extern "C" {
BASEPROJECT_API baseproject::IBaseProject* CreateBaseProject();
BASEPROJECT_API void DestroyBaseProject(baseproject::IBaseProject* obj);
}

typedef baseproject::IBaseProject* CreateBaseProjectType();
typedef void DestroyBaseProjectType(baseproject::IBaseProject* obj);
