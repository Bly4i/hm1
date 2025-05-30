#pragma once

#include <Wt/Dbo/Dbo>
#include <string>

class Shop
{
public:
    int id;
    std::string name;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::field(a, name, "name");
    }
};
