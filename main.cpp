#include <iostream>
using namespace std;

void Reg(void);
void Login(void);

int main()
{
    int input;
    while (true)
    {
        cout << "\nEnter 1 for Login\nEnter 2 for Registretion\nEnter 0 for Exit\n-> ";
        cin >> input;
        switch (input)
        {
        case 1:
            Login();
            break;
        case 2:
            Reg();
            break;
        case 0:
            cout << "Exit the program\n";
            exit(EXIT_SUCCESS);
        default:
            cout << "Choose the correct option\n";
            break;
        }
    }
    return 0;
}

void Reg()
{
    cout << "\n@\n";
}

void Login()
{
    cout << "\n@\n";
}