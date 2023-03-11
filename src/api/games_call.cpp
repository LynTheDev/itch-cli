#include "itch/games_call.h"
using json = nlohmann::json;

void api::call_all_games(const std::string& API_KEY) {
    std::string URL = "https://itch.io/api/1/" + API_KEY + "/my-games";

    curlpp::Easy req;
    req.setOpt(curlpp::options::Url(URL));

    std::list<std::string> header = {
        "Content-Type: application/json"
    };

    req.setOpt<curlpp::options::HttpHeader>(header);

    std::ostringstream out_stream;
    out_stream << req;

    std::string body = out_stream.str();
    json parser = json::parse(body);

    for (auto a : parser["games"]) {
        std::string title = a["title"].get<std::string>();
        int id = a["id"].get<int>();

        int views = a["views_count"].get<int>();
        int downloads = a["downloads_count"].get<int>();
        int purchases = a["purchases_count"].get<int>();
        std::string description = a["short_text"].get<std::string>();

        std::cout << "Title: " << title << "\n";
        std::cout << "ID: " << id << "\n";
        std::cout << "Views: " << views << "\n";
        std::cout << "Downloads: " << downloads << "\n";
        std::cout << "Purchases: " << purchases << "\n";
        std::cout << "TLDR: " << description << "\n";

        std::cout << "*----------------------------------------------------------------*\n";
    }
}

void api::call_game(const std::string &game_id, const std::string &API_KEY) {
    std::string URL = "https://itch.io/api/1/" + API_KEY + "/game/" + game_id;

    curlpp::Easy req;
    req.setOpt(curlpp::options::Url(URL));

    std::list<std::string> header = {
            "Content-Type: application/json"
    };

    req.setOpt<curlpp::options::HttpHeader>(header);

    std::ostringstream out_stream;
    out_stream << req;

    std::string body = out_stream.str();
    json parser = json::parse(body);

    std::string title = parser["game"]["title"].get<std::string>();
    std::string creator = parser["game"]["user"]["username"].get<std::string>();
    int id = parser["game"]["id"].get<int>();
    std::string description = parser["game"]["short_text"].get<std::string>();

    std::cout << "Title: " << title << "\n";
    std::cout << "Creator: " << creator << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "TLDR: " << description << "\n";
}