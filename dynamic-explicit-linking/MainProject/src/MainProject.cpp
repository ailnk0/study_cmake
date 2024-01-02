#include <memory>

#include "IBaseProject.h"

#ifdef WIN32
#include <Windows.h>
#elif __linux__
#include <dlfcn.h>
#endif

using namespace std;

#ifdef WIN32
class Loader {
 public:
  virtual ~Loader() { dispose(); }

 public:
  virtual bool init() {
    m_handle = LoadLibrary("BaseProject.dll");
    if (!m_handle) {
      std::cout << "LoadLibrary failed : " << GetLastError() << std::endl;
      return false;
    }

    m_CreateBaseProject = (CreateBaseProjectType*)GetProcAddress(m_handle, "CreateBaseProject");
    if (!m_CreateBaseProject) {
      std::cout << "GetProcAddress failed with m_CreateBaseProject : " << GetLastError()
                << std::endl;
      dispose();
      return false;
    }

    m_DestroyBaseProject = (DestroyBaseProjectType*)GetProcAddress(m_handle, "DestroyBaseProject");
    if (!m_DestroyBaseProject) {
      std::cout << "GetProcAddress failed with m_DestroyBaseProject : " << GetLastError()
                << std::endl;
      dispose();
      return false;
    }

    m_lib = m_CreateBaseProject();

    return true;
  }

  virtual void dispose() {
    if (m_lib) {
      m_DestroyBaseProject(m_lib);
      m_lib = nullptr;
    }

    if (m_handle) {
      FreeLibrary(m_handle);
      m_handle = nullptr;
      m_CreateBaseProject = nullptr;
      m_DestroyBaseProject = nullptr;
    }
  }

  virtual baseproject::IBaseProject* getLib() { return m_lib; }

 private:
  HMODULE m_handle = nullptr;
  baseproject::IBaseProject* m_lib = nullptr;
  CreateBaseProjectType* m_CreateBaseProject = nullptr;
  DestroyBaseProjectType* m_DestroyBaseProject = nullptr;
};
#elif __linux__
class Loader {
 public:
  virtual ~Loader() { dispose(); }

 public:
  virtual bool init() {
    m_handle = dlopen("./libBaseProject.so", RTLD_LAZY);
    if (!m_handle) {
      std::cout << "dlopen failed : " << dlerror() << std::endl;
      return false;
    }

    m_CreateBaseProject =
        (CreateBaseProjectType*)dlsym(m_handle, "CreateBaseProject");
    if (!m_CreateBaseProject) {
      std::cout << "dlsym failed with m_CreateBaseProject : " << dlerror()
                << std::endl;
      dispose();
      return false;
    }

    m_DestroyBaseProject =
        (DestroyBaseProjectType*)dlsym(m_handle, "DestroyBaseProject");
    if (!m_DestroyBaseProject) {
      std::cout << "dlsym failed with m_DestroyBaseProject : " << dlerror()
                << std::endl;
      dispose();
      return false;
    }

    m_lib = m_CreateBaseProject();

    return true;
  }

  virtual void dispose() {
    if (m_handle) {
      if (m_lib) {
        m_DestroyBaseProject(m_lib);
        m_lib = nullptr;
      }
      dlclose(m_handle);
      m_handle = nullptr;
      m_CreateBaseProject = nullptr;
      m_DestroyBaseProject = nullptr;
    }
  }

  virtual baseproject::IBaseProject* getLib() { return m_lib; }

 private:
  void* m_handle = nullptr;
  baseproject::IBaseProject* m_lib = nullptr;
  CreateBaseProjectType* m_CreateBaseProject = nullptr;
  DestroyBaseProjectType* m_DestroyBaseProject = nullptr;
};
#endif

int main() {
  auto loader = std::make_shared<Loader>();
  if (!loader->init()) {
    std::cout << "FAIL" << std::endl;
    return 1;
  }
  
  auto base = loader->getLib();
  base->printMsg();
  base->checkDef();
  std::cout << "DONE" << std::endl;

  return 0;
}
