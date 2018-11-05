#include <iostream>
#include <experimental/array>
#include <luna/luna.h>
#include <nlohmann/json.hpp>
#include "logger.h"

using namespace luna;

int main()
{
    // set up the loggers
    set_access_logger(access_logger);
    set_error_logger(error_logger);

    // determine which port to run on, default to 8080
    auto port = 8080;
    if (auto port_str = std::getenv("PORT"))
    {
        try
        {
            port = std::atoi(port_str);
        }
        catch (const std::invalid_argument &e)
        {
            error_logger(log_level::FATAL, "Invalid port specified in env $PORT.");
            return 1;
        }
        catch (const std::out_of_range &e)
        {
            error_logger(log_level::FATAL, "Port specified in env $PORT is too large.");
            return 1;
        }
    }

    // create a server
    server server;
    // add endpoints

    // File serving example; serve files from the assets folder on /
    auto routers = std::experimental::make_array("/", "/about", "/contact", 
                                                "/blogs", "/blogs/-([0-9a-zA-Z]{19})", 
                                                "/blogs/create", "/blogs/edit/-([0-9a-zA-Z]{19})");

    auto router = server.create_router("/");

    router->handle_request(request_method::GET, "/index.js",[] (auto req) -> response {
            response res = response::from_file("./assets/index.js");
            res.content_type = "text/javascript";
            return res;
        });
    
    router->handle_request(request_method::GET, "/blogs/edit/index.js",[] (auto req) -> response {
            response res = response::from_file("./assets/index.js");
            res.content_type = "text/javascript";
            return res;
        });

    router->handle_request(request_method::GET, "/blogs/index.js",[] (auto req) -> response {
            response res = response::from_file("./assets/index.js");
            res.content_type = "text/javascript";
            return res;
        });

    for(auto&& r : routers)
        router->handle_request(request_method::GET, 
                            r, 
                            [](auto request) -> response { 
                                response res = response::from_file("./assets/index.html");
                            return res;
                        });
    
    server.start(port);

    return 0;
}
