#include <iostream>

#include "hchat.h"

using namespace std;

int main() {
  string prompt;
  cout << "Enter a prompt: ";
  getline(cin, prompt);

  hchat::hchat h;
  auto code = h.chat(prompt);
  return code;
}
