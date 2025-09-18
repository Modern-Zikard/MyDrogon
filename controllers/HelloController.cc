#include "HelloController.h"
#include <drogon/HttpResponse.h>

using namespace drogon;

void HelloController::hello(const HttpRequestPtr& req,
    std::function<void(const HttpResponsePtr&)>&& callback) {
    auto resp = HttpResponse::newHttpResponse();
    resp->setBody("Hello, Drogon!");
    callback(resp);
}