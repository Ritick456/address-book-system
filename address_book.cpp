#include<iostream>
#include<vector>

using namespace std;

class Contact {
    public:
    string firstname;
    string lastname;
    string address;
    string city;
    string email;
    string state;
    string zip;
    string phonenumber;

    Contact(string firstname, string lastname, string address, string city, string state, string zip, string phonenumber, string email) {
        this->firstname = firstname;
        this->lastname = lastname;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->phonenumber = phonenumber;
        this->email = email;
    }
};

class Addressbook {
    public:
    vector<Contact> contacts;

    public:
    void addcontact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully!" << endl;
    }

    void editcontact(string firstname, string lastname) {
        for (auto& contact : contacts) {
            if (contact.firstname == firstname && contact.lastname == lastname) {
                cout << "Enter new first name: ";
                cin >> contact.firstname;

                cout << "Enter new last name: ";
                cin >> contact.lastname;

                cout << "Enter new address: ";
                cin.ignore();
                getline(cin, contact.address);

                cout << "Enter new city: ";
                cin >> contact.city;

                cout << "Enter new state: ";
                cin >> contact.state;

                cout << "Enter new zip: ";
                cin >> contact.zip;

                cout << "Enter new phone number: ";
                cin >> contact.phonenumber;

                cout << "Enter new email: ";
                cin >> contact.email;

                cout << "Contact updated successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found." << endl;
    }
};

int main() {
    Addressbook addressbook;
    string firstname, lastname, address, city, state, zip, phonenumber, email;

    cout << "Enter first name: ";
    cin >> firstname;

    cout << "Enter last name: ";
    cin >> lastname;

    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Enter city: ";
    cin >> city;

    cout << "Enter state: ";
    cin >> state;

    cout << "Enter zip: ";
    cin >> zip;

    cout << "Enter phone number: ";
    cin >> phonenumber;

    cout << "Enter email: ";
    cin >> email;

    Contact newContact(firstname, lastname, address, city, state, zip, phonenumber, email);
    addressbook.addcontact(newContact);

    string searchFirstName, searchLastName;
    cout << "Enter first name of contact to edit: ";
    cin >> searchFirstName;
    cout << "Enter last name of contact to edit: ";
    cin >> searchLastName;

    addressbook.editcontact(searchFirstName, searchLastName);

    cout << "Welcome to Address Book Program in AddressBookMain class on Master Branch" << endl;

    return 0;
}
