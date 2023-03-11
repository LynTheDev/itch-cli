#ifndef ITCH_GAMES_CALL_H
#define ITCH_GAMES_CALL_H

    #include <nlohmann/json.hpp>

    #include <curlpp/cURLpp.hpp>
    #include <curlpp/Easy.hpp>
    #include <curlpp/Options.hpp>
    #include <curlpp/Infos.hpp>

    #include <sstream>

    namespace api {
        void call_all_games(const std::string& API_KEY);
        void call_game(const std::string& game_id, const std::string& API_KEY);
    }

#endif //ITCH_GAMES_CALL_H
