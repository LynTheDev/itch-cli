#include "itch/main.h"

int main(int argc, char *argv[]) {
    auto path = (boost::dll::program_location().parent_path() / "data" / "key.txt").generic_string();
    utils::read_key(API_KEY, path);

    std::string game_id = "nil";
    bool get_all = false;
    bool help = false;

    auto cli = lyra::cli() |
            lyra::opt(get_all)
            ["-a"]["--all"]
            ("Get all the games you've released.") |

            lyra::opt(game_id, "id")
            ["-g"]["--get"]
            ("Get a specific game using it's id") |

            lyra::help(help)
            ("Show app description.");

    auto result = cli.parse( { argc, argv } );
    if (!result) {
        std::cerr << "Error in command line: " << result.message() << std::endl;
        return -1;
    }

    if (help || argc == 1) {
        std::cout << cli << std::endl;
        return 0;
    }

    if (game_id != "nil") {
        api::call_game("1960070", API_KEY);
    }

    if(get_all) {
        api::call_all_games(API_KEY);
    }

return 0;
}
