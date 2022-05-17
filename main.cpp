#include "includes/Parsing.hpp"

int main(int argc, char const *argv[])
{
    try {
        if (argc == 2){
            std::vector<Server_block> all_servers;
            all_servers = parsse_the_config_file(argv[1]);
            start_servers(all_servers);
        }
        else{
            std::cerr << "ENTER A FILE PATH" << std::endl;
        }
    }
    catch (char const *e){
        std::cout << "ERROR HAS BEN FOUND : " << e << std::endl ;
    }
    return 0;
}