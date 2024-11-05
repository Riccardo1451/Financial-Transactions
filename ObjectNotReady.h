//
// Created by Riccardo fantechi on 05/11/24.
//

#ifndef OBJECTNOTREADY_H
#define OBJECTNOTREADY_H
#include <stdexcept>
#include <string>

class ObjectNotReady : public std::runtime_error{
public:

    explicit ObjectNotReady(const std::string& msg) : std::runtime_error("Oggetto non pronto: " + msg) {};
};
#endif //OBJECTNOTREADY_H
