
#ifndef OBJNOTFOUND_H
#define OBJNOTFOUND_H

#include <stdexcept>
#include <string>


class ObjectNotFound : public std::runtime_error {
public:
    explicit ObjectNotFound(const std::string& msg) : std::runtime_error("Oggetto non trovato: " + msg) {}
};



#endif //OBJNOTFOUND_H
