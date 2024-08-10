//Develop a program that allows users to store and manage contact information. The program should provide options to add a new contact by entering their name, phone number, and email address. It should also allow users to view their contact list, edit existing contacts, and delete contacts if needed. The program should store the contacts in memory or in a file for persistent storage.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};

void saveContactsToFile(const vector<Contact>& contacts) {
    ofstream outFile("contacts.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (const auto& contact : contacts) {
        outFile << contact.name << endl;
        outFile << contact.phoneNumber << endl;
        outFile << contact.email << endl;
    }
    outFile.close();
}

void loadContactsFromFile(vector<Contact>& contacts) {
    ifstream inFile("contacts.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    Contact contact;
    while (getline(inFile, contact.name)) {
        getline(inFile, contact.phoneNumber);
        getline(inFile, contact.email);
        contacts.push_back(contact);
    }
    inFile.close();
}

void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter Phone Number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter Email: ";
    getline(cin, newContact.email);
    contacts.push_back(newContact);
    saveContactsToFile(contacts);
}

void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display!" << endl;
        return;
    }

    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << "Contact " << i + 1 << ":" << endl;
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone Number: " << contacts[i].phoneNumber << endl;
        cout << "Email: " << contacts[i].email << endl;
        cout << "-------------------------" << endl;
    }
}

void editContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to edit!" << endl;
        return;
    }

    viewContacts(contacts);
    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;

    if (index <= 0 || index > contacts.size()) {
        cout << "Invalid contact number!" << endl;
        return;
    }

    Contact& contact = contacts[index - 1];
    cout << "Editing Contact " << index << ":" << endl;
    cout << "Enter new Name (current: " << contact.name << "): ";
    cin.ignore();
    getline(cin, contact.name);
    cout << "Enter new Phone Number (current: " << contact.phoneNumber << "): ";
    getline(cin, contact.phoneNumber);
    cout << "Enter new Email (current: " << contact.email << "): ";
    getline(cin, contact.email);

    saveContactsToFile(contacts);
}

void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete!" << endl;
        return;
    }

    viewContacts(contacts);
    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;

    if (index <= 0 || index > contacts.size()) {
        cout << "Invalid contact number!" << endl;
        return;
    }

    contacts.erase(contacts.begin() + index - 1);
    saveContactsToFile(contacts);
    cout << "Contact deleted successfully!" << endl;
}

int main() {
    vector<Contact> contacts;
    loadContactsFromFile(contacts);

    int choice;
    do {
        cout << "Contact Manager" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. View Contacts" << endl;
        cout << "3. Edit Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}