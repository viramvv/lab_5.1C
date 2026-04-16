#pragma once
#include <exception>
#include <string>

class MoneyException : public std::exception {
    std::string message;
public:
    MoneyException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};