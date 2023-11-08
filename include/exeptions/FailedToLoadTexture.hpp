#pragma once
#include <iostream>

class FailedToLoadTexture : std::exception {
public:
  FailedToLoadTexture(std::string msg) : msg(msg) {}
  // sobrecarga del metodo de error...
  const char *what() const noexcept override {
    return std::string("failed to load: " + this->msg).c_str();
  }

private:
  std::string msg;
};