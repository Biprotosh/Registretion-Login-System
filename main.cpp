#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class features
{
public:
    void options(string username);
    void printInfo(void);
    void changeCredential(void);
    void changeUserPass(void);
    void dltAcc(string username);
};

void features::printInfo(){
    cout<<"Under construction\n";
}

void features::changeCredential(){
    cout<<"Under construction\n";
}

void features::changeUserPass(){
    cout<<"Under construction\n";
}

void features::dltAcc(string username){
    if(remove(username.append(".txt").c_str())==0){
        cout<<"\nYour account successfully deleted\n";
    }
}

void features::options(string username)
{
    while (true)
    {
        char choice;
        cout << "\n________________/ OPTIONS \\________________" << endl;
        cout << "| Click 1 for Printing the information   |" << endl;
        cout << "| Click 2 for change the credential      |" << endl;
        cout << "| Click 3 for change username & Password |" << endl;
        cout << "| Click 4 for logout                     |" << endl;
        cout << "| Click 5 for Delete your accout         |" << endl;
        cout << endl
             << "Enter you choice -> ";
        cin >> choice;
        getchar();
        switch (choice)
        {
        case '1':
            printInfo();
            break;
        case '2':
            changeCredential();
            break;
        case '3':
            changeUserPass();
            break;
        case '4': 
            cout<<"\nLogout successfully!!\n";    
            return ;
        case '5':
            dltAcc(username);
            return;
        default:
            cout << "\nInvalid choice\n";
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
            cout << "Name: ";
            getline(cin, name);
            cout << "Phone-Number: ";
            cin >> phN;
            userFile << "Name: " << name << endl
                     << "Phone Number: " << phN << endl
                     << "User Name: " << username << endl
                     << "Password: " << password;
            userFile.close();
            check.close();
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
    string storedPassword;

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

    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    if (checkCredentials(username, password))
    {
        cout << "\nLogged in successfully!" << endl;
        features show;
        show.options(username);
    }
    else
    {
        cout << "\nInvalid username or password. Please try again." << endl;
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