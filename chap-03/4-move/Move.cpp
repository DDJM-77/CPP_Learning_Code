#include <iostream>
#include <memory>

void display(const std::string& variable_name, const std::unique_ptr<int>& variable)
{
    if (!variable)
    {
        std::cout << variable_name << " is empty" << std::endl;
    }
    else
    {
        std::cout << variable_name << " contains " << *variable << std::endl;
    }
}

std::unique_ptr<int> passthrough(std::unique_ptr<int> i)
{
    std::cout << "Before move in passthrough" << std::endl;
    display("i", i);
    std::cout << "--------------------------" << std::endl;

    auto i_loc = std::move(i);

    std::cout << "After move in passthrough" << std::endl;
    display("i_loc", i_loc);
    display("i", i);
    std::cout << "--------------------------" << std::endl;
    return i_loc;
}

int main()
{
    std::unique_ptr<int> i1 = std::make_unique<int>(3);
    std::unique_ptr<int> i2 = std::make_unique<int>(8);

    std::cout << "Before passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    i2 = passthrough(std::move(i1));

    std::cout << "After passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    return 0;
}