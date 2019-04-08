#include "common.hxx"
#include "data.hxx"

#include "metayamlfmt.hxx"
#include "metayamlcpp.hxx"
#include "yamlcpp.hxx"

int main(int, char**) {
  // Serialize a number.
  int number = 42;

  std::cout << "===============\tNUMBER\t===============" << std::endl;
  std::cout << "===============\tMETA YAML FMT" << std::endl;
  std::cout << metayamlfmt_encoder(number) << std::endl;
  std::cout << "===============\tMETA YAML CPP" << std::endl;
  std::cout << metayamlcpp_encoder(number) << std::endl;
  std::cout << "\n\n";

  // Serialize a vector.
  std::vector<employee> employees = {
    {"Steve Jobs", 1},
    {"Tim Cook", 3000000}
  };

  std::cout << "===============\tEMPLOYEES\t===============" << std::endl;
  std::cout << "===============\tMETA YAML FMT" << std::endl;
  std::cout << metayamlfmt_encoder(employees) << std::endl;
  std::cout << "===============\tMETA YAML CPP" << std::endl;
  std::cout << metayamlcpp_encoder(employees) << std::endl;
  std::cout << "\n\n";

  // Serialize an organization.
  organization apple = {"Apple", employees};\

  std::cout << "===============\tORGANIZATION\t===============" << std::endl;
  std::cout << "===============\tMETA YAML FMT" << std::endl;
  std::cout << metayamlfmt_encoder(apple) << std::endl;
  std::cout << "===============\tMETA YAML CPP" << std::endl;
  std::cout << metayamlcpp_encoder(apple) << std::endl;
  std::cout << "\n\n";
}
