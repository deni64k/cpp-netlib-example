#include <iostream>
#include <string>
#include <fstream>

#include <network/http/client.hpp>

namespace http = network::http;

void fetch(std::string const &url) {
  http::client client;
  http::request request{network::uri{url}};
  request.version("1.1");
  request.append_header("Connection", "close");

  auto future_response = client.get(request);
  auto response = future_response.get();
  std::cout << response.body() << std::endl;
}

void usage(char const *progname) {
  std::cerr << "Usage: " << progname << " <URL>" << std::endl;
}

int main(int argc, char const *argv[])
{
  if (argc < 2) {
    usage(argv[0]);
    return 1;
  }

  try {
    fetch(argv[1]);
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
