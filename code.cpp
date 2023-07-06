#include <bits/stdc++.h>
using namespace std;
int main()
{
    int choice;
    while (true)
    {
        cout << "Hello, Would you want to login,register or exit?" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            ifstream file("record.txt");
            if (!file.is_open())
            {
                cout << "Failed to open the file!...." << endl;
                return 1;
            }
            string userName, password;
            cout << "Enter your Username to proceed :" << endl;
            cin >> userName;
            cout << "Enter your Password to proceed :" << endl;
            cin >> password;

            string line;
            bool found = false;
            while (getline(file, line))
            {
                if (line.find(userName) != string::npos)
                {
                    cout << "Loged in Successfully. " << line << endl;
                    found = true;
                }
            }

            if (!found)
            {
                cout << "UserName not found." << endl;
            }

            file.close();
            break;
        }

        case 2:
        {
            string filename = "record.txt";
            ofstream outfile(filename, ios::app);
            if (outfile.is_open())
            {
                string firstName, lastName, email, password, userName;
                cout << "Enter your first name:" << endl;
                cin.ignore();
                getline(cin, firstName);
                cout << "Enter your last name:" << endl;
                getline(cin, lastName);
                cout << "Enter your email address:" << endl;
                getline(cin, email);
                cout << "Enter the User Name:" << endl;
                getline(cin, userName);
                cout << "Enter your password:" << endl;
                getline(cin, password);

                outfile << "FirstName: " << firstName << endl;
                outfile << "LastName: " << lastName << endl;
                outfile << "Email: " << email << endl;
                outfile << "UserName: " << userName << endl;
                outfile << "Password: " << password << endl;
                cin.ignore();
            }
            outfile.close();
            cout << "Record has been added successfully:" << endl;
            break;
        }
        case 3:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Wrong Choice" << endl;
            return 1;
        }
    }
    return 0;
}