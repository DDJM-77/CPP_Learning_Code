#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string word = "";
    for (int i = 0; i < 10; i++)
    {
        cin >> word;
        if (word == "-1")
        {
            return 0;
        }
        cout << "The number you choose is " << word << endl;
    }
    return 0;
}
