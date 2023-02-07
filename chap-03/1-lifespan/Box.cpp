#include "Box.h"

#include <iostream>

int main()
{
    std::cout << "Main start" << std::endl;
    Box*     box         = new Box("gift");
    Content& content_ref = box->get_content();
    std::cout << content_ref.name << std::endl;
    delete box;
    // content_ref.name = "chocolate";
    std::cout << content_ref.name << std::endl;
    std::cout << "Main end" << std::endl;

    return 0;
}
