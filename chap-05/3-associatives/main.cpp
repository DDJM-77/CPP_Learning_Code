#include "keys.h"

#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

int main()
{
    // Set
    std::set<ComparableDog> dogs;

    ComparableDog medor { "medor", "labrador" };
    dogs.emplace(medor);

    ComparableDog gus { "gus", "bordercollie" };
    dogs.emplace(gus);

    std::cout << dogs.size() << std::endl;

    // Unordered sets
    std::unordered_set<HashableDog> dogs_hash;

    HashableDog medor_hash { "medor", "labrador" };
    dogs_hash.emplace(medor_hash);

    using Owner = std::pair<std::string, std::string>;
    std::map<ComparableDog, Owner> owners_by_dog;

    ComparableDog medor2 { "medor", "labrador" };
    ComparableDog gus2 { "gus", "bordercollie" };
    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };

    owners_by_dog.insert(std::make_pair(medor2, Owner { "Claire", "David" }));
    owners_by_dog.insert_or_assign(gus2, Owner { "Marc", "Zipstein" });
    owners_by_dog.emplace(zim, Owner { "Céline", "Noël" });
    owners_by_dog.try_emplace(flippy, "Vincent", "Nozick");

    owners_by_dog.emplace(gus2, Owner { "Claire", "David" });
    // -> gus is still owned by Marc (emplace does not modify values with existing keys, neither does insert
    // or try_emplace)

    owners_by_dog.insert_or_assign(gus2, Owner { "Vincent", "Nozick" });
    // -> gus is now owned by Vincent (insert_or_assign reassign values with existing keys)

    return 0;
}