#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Reg(void);
void Login(void);

string username = "", password = "";

int main()
{
    int input;
    while (true)
    {
        cout << "\nEnter 1 for Login\nEnter 2 for Registration\nEnter 0 for Exit\n-> ";
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
    cout << "Enter Username: ";
    cin >> username;
    cout << "\n";
    cout << "Enter Password: ";
    cin >> password;
    cout << username << endl;
    cout << password << endl;
    ofstream reg ("reg.txt");
    if (reg.is_open())
    {
        reg << username << endl;
        reg << password << endl;
    }
    
    Login();
}

void Login()
{
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
}