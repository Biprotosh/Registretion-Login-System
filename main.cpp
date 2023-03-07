#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser()
{
    string username, password, checkUser;
    string name, phN;
    ifstream check;
    while (true)
    {
        cout << endl
             << "Enter your Username: ";
        cin >> username;
        checkUser = username;
        check.open(checkUser.append(".txt"));
        // cout<<checkUser;
        if (check.is_open())
        {
            cout << "\nUser name is already exist\nPlease enter a different user name"
                 << endl;
            continue;
        }

        else if (!check.is_open())
        {
            cout << "Enter your password: ";
            cin >> password;
            ofstream userFile(username + ".txt");
            cout << "\nEnter you credential\n";
            cout << "--------------------\n";
            getchar();
            cout<<"Name: ";
            getline(cin, name);
            cout<<"Phone-Number: ";
            cin>>phN;
            userFile <<"Name: "<<name<<endl<<"Phone Number: "<<phN<<endl<<"User Name: "<<username<<endl<<"Password: "<<password ;
            userFile.close();

            cout << "\nUser registered successfully!\nLogin for use features" << endl;
            break;
        }
        else
        {
            cout << "Something went wrong\n";
            exit(1);
        }
    }
}

bool checkCredentials(string username, string password)
{
    ifstream userFile(username + ".txt");

    if (userFile.is_open())
    {
        string storedUsername, storedPassword;

        getline(userFile, storedUsername);
        getline(userFile, storedPassword);

        if (storedUsername == username && storedPassword == password)
        {
            userFile.close();
            return true;
        }
    }

    userFile.close();
    return false;
}

void login()
{
    string username, password;

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    if (checkCredentials(username, password))
    {
        cout << "Login successful!" << endl;
    }
    else
    {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

int main()
{

    char choice;
    while (true)
    {
        cout << endl
             << "------------------" << endl;
        cout << "| 1 for Register |" << endl;
        cout << "| 2 for Login    |" << endl;
        cout << "| 3 for Exit     |" << endl;
        cout << "------------------" << endl;
        cout << "Enter your choice -> ";
        cin >> choice;
        // cout<<choice<<endl;
        getchar(); // For consume the new line character
        switch (choice)
        {
        case '1':
            registerUser();
            break;
        case '2':
            login();
            break;
        case '3':
            cout << endl
                 << "Goodbye!" << endl;
            exit(0);
        default:
            cout << endl
                 << "Invalid choice. Please try again." << endl;
            continue;
        }
    }

    return 0;
}