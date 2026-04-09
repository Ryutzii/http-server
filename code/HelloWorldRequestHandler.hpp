/// @copyright Copyright (c) 2026 Ángel, All rights reserved.
/// angel.rodriguez@udit.es

#pragma once

#include <HttpRequestHandler.hpp>
#include <HttpResponse.hpp>

namespace argb
{

    class HelloWorldRequestHandler : public HttpRequestHandler
    {
        static constexpr std::string_view message = "Hello World!";

    public:

        void handle_request (HttpMessage::Id , const HttpRequest & , HttpResponse & response) override
        {
            HttpResponse::Serializer{ response }
                .status     (200)
                .header     ("Content-Type",   "text/plain")
                .header     ("Content-Length", "12"        )
                .header     ("Connection",     "close"     )
                .end_header ()
                .body       (message);
        }

    };

}
