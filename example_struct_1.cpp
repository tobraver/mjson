#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct person_t
{
    std::string name;
    std::vector<float> socres;
    int age;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(person_t, name, socres, age)


int main(int argc, char const *argv[])
{
    person_t p1;
    p1.name = "wang";
    p1.socres.push_back(11);
    p1.socres.push_back(12);
    p1.socres.push_back(13);
    p1.age = 18;

    json j = p1;
    
    std::cout << j.dump(4) << std::endl;

    person_t p2 = j.template get<person_t>();

    std::cout << "name: " << p2.name << std::endl;
    std::cout << "scores size: " << p2.socres.size() << std::endl;
    for(auto it : p2.socres)
    {
        std::cout << "socre: " << it << std::endl;
    }
    std::cout << "age: " << p2.age << std::endl;
    
    return 0;
}



