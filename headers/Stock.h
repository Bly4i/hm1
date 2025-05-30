#pragma once

#include <Wt/Dbo/Dbo>
#include "Book.h"
#include "Shop.h"

class Stock
{
public:
    int id;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    int count;

    template<class Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, id, "id");
        Wt::Dbo::belongsTo(a, book, "id_book");
        Wt::Dbo::belongsTo(a, shop, "id_shop");
        Wt::Dbo::field(a, count, "count");
    }
};
