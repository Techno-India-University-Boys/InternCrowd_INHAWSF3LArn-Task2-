#include <bits/stdc++.h>
using namespace std;

struct FamilyMember
{
    string name;
    string dob;
    string email;
};
int main()
{
    vector<FamilyMember> familyMembers;
    int choice;
    while (true)
    {

        cout << "Enter the choice for the operation you want to perform:" << endl;
        cout<<endl;
        cout << "1. Add a new family member." << endl;
        cout << "2. Search for the family member." << endl;
        cout << "3. Show all the family members." << endl;
        cout << "4. Exit the program:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            FamilyMember member;
            char option;
            do
            {
                cout << "Enter the name of the family member:" << endl;
                cin.ignore();
                getline(cin, member.name);

                cout << "Enter the date of birth of the family member in DD/MM/YYYY format:" << endl;
                getline(cin, member.dob);

                cout << "Enter the email of the family member:" << endl;
                getline(cin, member.email);

                familyMembers.push_back(member);

                cout << "Do you want to add more data (Y/N)?" << endl;
                cin >> option;
                cout<<endl;
            } while (option == 'Y' || option == 'y');
            cout << "Family member added successfully." << endl;
            cout<<endl;
            break;
        }
        case 2:
        {
            string searchName;
            cout << "Enter the name to search: "<<endl;;
            cin.ignore();
            getline(cin, searchName);

            transform(searchName.begin(), searchName.end(), searchName.begin(), ::tolower);

            bool found = false;
            for (const auto &member : familyMembers)
            {
                string name = member.name;
                transform(name.begin(), name.end(), name.begin(), ::tolower);

                if (name == searchName)
                {
                    cout << "Family member found:" << endl;
                    cout << "Name: " << member.name << endl;
                    cout << "Date of Birth: " << member.dob << endl;
                    cout << "Email: " << member.email << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Family member not found." << endl;
            }
            break;
        }
        case 3:
        {
            int n = familyMembers.size();
            cout << "Here is the list" << endl;
            for (int i = 0; i < n; i++)
            {
                string name=familyMembers[i].name;
                string dob=familyMembers[i].dob;
                string email=familyMembers[i].email;
                cout<<"Name : "<<name<<endl;
                cout<<"Date of Birth : "<<dob<<endl;
                cout<<"Email : "<<email<<endl;
                cout << endl;
            }
            break;
        }
        case 4:
        {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
        {
            cout << "Wrong Choice:" << endl;
            break;
        }
        }
    }
    return 0;
}
