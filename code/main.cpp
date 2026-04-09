
/// @copyright Copyright (c) 2026 Ángel, All rights reserved.
/// angel.rodriguez@udit.es

#include <HttpServer.hpp>
#include <iostream>
#include <NetworkSetup.hpp>
#include "SignalHandler.hpp"
#include "HelloWorldRequestHandler.hpp"

using namespace argb;

int main ()
{
    try
    {
        NetworkSetup network_setup;
        HttpServer   server;
        Port         port{ 80 };
        
        HelloWorldRequestHandler hello_world_handler;

        server.set_default_handler (&hello_world_handler);

        std::cout << "Running HTTP server on port " << static_cast<uint16_t>(port) << "..." << std::endl;

        SignalHandler::handle (server);

        server.run (port);
    }
    catch (const NetworkException & exception)
    {
        std::cout << "Network exception: " << exception << std::endl;

        return 1;
    }

    return 0;
}
