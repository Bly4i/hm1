#include <iostream>
#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Postgres>
#include "Publisher.h"
#include "Book.h"
#include "Shop.h"
#include "Stock.h"
#include "Sale.h"

namespace Dbo = Wt::Dbo;

int main() {
    try {
        std::string connectionString = "dbname=postgres user=postgres password=kima123 host=localhost port=5432";

        std::unique_ptr<Dbo::backend::Postgres> postgres = std::make_unique<Dbo::backend::Postgres>(connectionString);
        Dbo::Session session;
        session.setBackend(std::move(postgres));

        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Stock>("stock");
        session.mapClass<Sale>("sale");

        session.createTables();

        Dbo::Transaction transaction(session);
        Publisher* publisher = new Publisher();
        publisher->name = "Example Publisher";
        Dbo::ptr<Publisher> publisherPtr = session.add(publisher);

        Book* book = new Book();
        book->title = "Example Book";
        book->publisher = publisherPtr;
        session.add(book);

        transaction.commit();

        std::cout << "Data added successfully!" << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
