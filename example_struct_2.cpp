#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct socre_t
{
    std::string course;
    float       score;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(socre_t, course, score)

struct person_t
{
    std::string name;
    std::vector<socre_t> socres;
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(person_t, name, socres)


int main(int argc, char const *argv[])
{
    person_t p1;
    p1.name = "wang";

    socre_t s1;
    s1.course = "english";
    s1.score = 100;
    p1.socres.push_back(s1);

    s1.course = "math";
    s1.score = 99.8;
    p1.socres.push_back(s1);

    json j = p1;
    
    std::cout << j.dump(4) << std::endl;

    person_t p2 = j.template get<person_t>();
    
    std::cout << "name: " << p2.name << std::endl;
    std::cout << "scores size: " << p2.socres.size() << std::endl;
    for(auto it : p2.socres)
    {
        std::cout << "course: " << it.course << std::endl;
        std::cout << "score: " << it.score << std::endl;
    }
    
    return 0;
}



