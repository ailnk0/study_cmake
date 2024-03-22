#include <string>

namespace hchat {

using namespace std;

class hchat {
 public:
  string getHello();
  string getModelPath();
  int chat(const string& prompt);
};

}  // namespace hchat
