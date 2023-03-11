#include "itch/read_key.h"

void utils::read_key(std::string &API_KEY, const std::string& PATH) {
    std::ifstream s(PATH);
    if (!s.is_open()) {
        throw std::runtime_error("Could not open " + PATH + ".");
    }

    while (!s.eof()) {
        std::string line;
        std::getline(s, line);

        if (!line.empty()) {
            API_KEY = line;
            break;
        }
    }

    s.close();
}