#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class features
{

public:
    void options(string username);
    void printInfo(string username);
    void changeCredential(string username);
    void changeUserPass(string username);
    void dltAcc(string username);
};

void features::printInfo(string username)
{
    string _PrintingInformation;
    username.append(".txt");
    ifstream Print(username.c_str());
    if (Print.is_open())
    {
        cout << "\nYour Informaition\n";
        cout << "------------------\n";
        while (!Print.eof())
        {
            getline(Print, _PrintingInformation);
            cout << _PrintingInformation << endl;
        }
        cout << "------------------\n";
        Print.close();
    }
    else
    {
        cout << "\nFile is not opening\n";
    }
}

void features::changeCredential(string username)
{
    string INFO1, INFO2, INFO3, INFO4;
    ifstream Read;
    ofstream Write;
    Read.open((username + ".txt").c_str());
    if (Read.is_open())
    {
        getline(Read, INFO1);
        getline(Read, INFO2);
        getline(Read, INFO3);
        getline(Read, INFO4);
        Read.close();
    }
    else
    {
        cout << "\nSomething went wrong\n";
    }

    Write.open((username + ".txt").c_str());
    if (Write.is_open())
    {
        cout << "Enter you name: ";
        getline(cin, INFO1);
        cout << "Enter your Phone-Number: ";
        getline(cin, INFO2);
        Write << "Name: " << INFO1 << endl;
        Write << "Phone Number: " << INFO2 << endl;
        Write << INFO3 << endl;
        Write << INFO4 << endl;
        cout << "\nYour Credential has been changed\n";
        Write.close();
    }
    else
    {
        cout << "\nSomething went wrong\n";
    }
}

void features::changeUserPass(string username)
{
    string NewUserName, NewPassword, shift, shift1;
    ifstream Check;
    while (true)
    {
        std::cout << "Enter your new username: ";
        std::getline(std::cin, NewUserName);
        cin.sync();
        Check.open((NewUserName + ".txt").c_str());
        if (Check.is_open())
        {
            cout << "\nUser name already exsits\nPlease enter a different username\n\n";
            Check.close();
            continue;
        }

        if (NewUserName.size() < 5 || NewUserName.size() > 14)
        {
            std::cout << "\nYour Username must be under 5 to 14 characters\n\n";
            Check.close();
            continue;
        }

        std::cout << "Enter your new password: ";
        std::cin >> NewPassword;
        if (NewPassword.size() < 4 || NewPassword.size() > 10)
        {
            cout << "\nYour Password must be under 4 to 10 characters\n";
            Check.close();
            continue;
        }
        Check.close();
        break;
    }

    rename((username + ".txt").c_str(), (NewUserName + ".txt").c_str());
    ifstream convert((NewUserName + ".txt").c_str());
    if (convert.is_open())
    {
        getline(convert, shift);
        getline(convert, shift1);
        convert.close();
    }
    else
    {
        cout << "\nSomething went wrond\n";
    }

    ofstream Write((NewUserName + ".txt").c_str());
    if (Write.is_open())
    {
        Write << shift << endl;
        Write << shift1 << endl;
        Write <<"User Name: "<< NewUserName << endl;
        Write << "Password: "<<NewPassword;
        Write.close();
    }
    else
    {
        cout << "\nSomething went wrond\n";
    }
    cout<<"\nYour username and password is successfully changed\nNow Login with you new username and password to access the file\n";
}

void features::dltAcc(string username)
{
    if (remove(username.append(".txt").c_str()) == 0)
    {
        std::cout << "\nYour account successfully deleted\n";
    }
    else
    {
        std::cout << "\nSome thing went wrong\n";
    }
}

void features::options(string username)
{
    while (true)
    {
        char choice;
        std::cout << "\n_______________/ OPTIONS \\________________" << endl;
        std::cout << "| Click 1 for Printing the information   |" << endl;
        std::cout << "| Click 2 for change the credential      |" << endl;
        std::cout << "| Click 3 for change username & Password |" << endl;
        std::cout << "| Click 4 for logout                     |" << endl;
        std::cout << "| Click 5 for Delete your Accout         |" << endl;
        std::cout << endl
                  << "Enter you choice -> ";
        std::cin >> choice;
        getchar();
        switch (choice)
        {
        case '1':
            printInfo(username);
            break;
        case '2':
            changeCredential(username);
            break;
        case '3':
            changeUserPass(username);
            return;
        case '4':
            std::cout << "\nLogout successfully!!\n";
            return;
        case '5':
            dltAcc(username);
            return;
        default:
            std::cout << "\nInvalid choice\n";
            break;
        }
    }
}

void registerUser()
{
    string username, password, checkUser;
    string name, phN;
    ifstream check;
    while (true)
    {
        std::cout << endl
                  << "Enter your Username: ";
        std::getline(std::cin, username);
        cin.sync();
        checkUser = username;
        if (checkUser.length() < 5 || checkUser.length() > 14)
        {
            cout << "\nYour Username must be under 5 to 14 characters\n";
            continue;
        }
        checkUser.append(".txt");
        check.open(checkUser.c_str());
        if (check.is_open())
        {
            std::cout << "\nUser name is already exist\nPlease enter a different user name"
                      << endl;
            check.close();
            continue;
        }

        else if (!check.is_open())
        {
            while (true)
            {
                std::cout << "Enter your password: ";
                std::cin >> password;
                if (password.length() < 4 || password.length() > 10)
                {
                    cout << "\nYour Password must be under 4 to 10 characters\n";
                    continue;
                }
                break;
            }
            cin.sync();
            ofstream userFile(checkUser.c_str());
            std::cout << "\nEnter you credential\n";
            std::cout << "--------------------\n";
            std::cout << "Name: ";
            std::getline(std::cin>>ws, name);
            cin.sync();
            std::cout << "Phone-Number: ";
            std::cin >> phN;
            cin.sync();
            userFile << "Name: " << name << endl
                     << "Phone Number: " << phN << endl
                     << "User Name: " << username << endl
                     << "Password: " << password;
            userFile.close();
            check.close();
            std::cout << "\nUser registered successfully!\nLogin for use features" << endl;
            check.close();
            break;
        }
        else
        {
            std::cout << "Something went wrong :)\n";
            check.close();
            exit(1);
        }
    }
}

bool checkCredentials(string username, string password)
{
    string storedPassword;
    username.append(".txt");
    ifstream userFile(username.c_str());

    if (userFile.is_open())
    {
        while (!userFile.eof())
        {
            userFile >> storedPassword;
        }

        if (!storedPassword.compare(password))
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

    std::cout << "Enter your username: ";
    std::getline(std::cin>>ws, username);
    cin.sync();
    std::cout << "Enter your password: ";
    std::cin >> password;
    cin.sync();

    if (checkCredentials(username, password))
    {
        std::cout << "\nLogged in successfully!" << endl;
        features show;
        show.options(username);
    }
    else
    {
        std::cout << "\nInvalid username or password. Please try again." << endl;
    }
}

int main()
{

    char choice;
    while (true)
    {
        std::cout << endl
                  << "------------------" << endl;
        std::cout << "| 1 for Register |" << endl;
        std::cout << "| 2 for Login    |" << endl;
        std::cout << "| 3 for Exit     |" << endl;
        std::cout << "------------------" << endl;
        std::cout << "Enter your choice -> ";
        std::cin >> choice;
        cin.sync(); // For clear the input buffer
        switch (choice)
        {
        case '1':
            registerUser();
            break;
        case '2':
            login();
            break;
        case '3':
            std::cout << endl
                      << "Goodbye!" << endl;
            exit(0);
        default:
            std::cout << endl
                      << "Invalid choice. Please try again." << endl;
            continue;
        }
    }

    return 0;
}
