#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
using namespace std;

class Contact{
    public:
    string firstname;
    string lastname;
    string address;
    string city;
    string email;
    string state;
    string zip;
    string phonenumber;

    Contact(string firstname, string lastname, string address, string city, string state, string zip, string phonenumber, string email){
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

class Addressbook{
    public:
    vector<Contact> contacts;

    public:
    void addcontact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Contact added successfully!" << endl;
    }

    void editcontact(string &firstname , string &lastname){
        for(auto& contact : contacts){
            if(contact.firstname == firstname && contact.lastname == lastname){
                cout<<"Enter new firstname : "<<endl;
                cin>>contact.firstname;

                cout<<"Enter new lastname : "<<endl;
                cin>>contact.lastname;

                cout<<"Enter new address : "<<endl;
                cin.ignore();
                getline(cin , contact.address);

                cout<<"Enter new city : "<<endl;
                cin>>contact.city;

                cout<<"Enter new state : "<<endl;
                cin>>contact.state;

                cout<<"Enter new zip : "<<endl;
                cin>>contact.zip;

                cout<<"Enter new phonenumber : "<<endl;
                cin>>contact.phonenumber;

                cout<<"Enter new email : "<<endl;
                cin>>contact.email;

                cout<<"Contact updated succesfully " << endl;
                return;
            }
        }
        cout<<"Contact not found"<< endl;
    }

    void deletecontact(string &firstname, string &lastname){
        for(auto it=contacts.begin() ; it!=contacts.end(); ++it){
            if(it->firstname == firstname && it->lastname == lastname){
                contacts.erase(it);
                cout<<"Contact deleted successfully!"<<endl;
                return;
            }
        }
        cout<<"Contact not found"<<endl;
    }
};

int main(){
    unordered_map<string, Addressbook> addressbooks;
    int choice = 0;
    
    while(choice != 6){
        cout<<"System Menu:" << endl;
        cout<<"1. Add a new Address Book"<<endl;
        cout<<"2. Add a contact to an Address Book"<<endl;
        cout<<"3. Display all contacts in an Address Book"<<endl;
        cout<<"4. Edit a contact in an Address Book"<<endl;
        cout<<"5. Delete a contact in an Address Book"<<endl;
        cout<<"6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: {
            string addressbookname;
            cout<<"Enter the name of the addressbook"<<endl;
            cin>>addressbookname;

            if(addressbooks.find(addressbookname) == addressbooks.end()){
                addressbooks[addressbookname] = Addressbook();
                cout<<"Address book created successfully"<<endl;
            } else {
                cout<<"Address book exists already"<<endl;
            }
            break;
        }
        case 2: {
            string addressbookname;
            cout<<"Enter the name of the addressbook"<<endl;
            cin>>addressbookname;

            if(addressbooks.find(addressbookname) != addressbooks.end()){
                string firstname, lastname, address, city, state, zip, phonenumber, email;

                cout<<"Enter firstname : "<<endl;
                cin>>firstname;

                cout<<"Enter lastname : "<<endl;
                cin>>lastname;

                cout<<"Enter address : "<<endl;
                cin.ignore();
                getline(cin , address);

                cout<<"Enter city : "<<endl;
                cin>>city;

                cout<<"Enter state : "<<endl;
                cin>>state;

                cout<<"Enter zip : "<<endl;
                cin>>zip;

                cout<<"Enter phonenumber : "<<endl;
                cin>>phonenumber;

                cout<<"Enter email : "<<endl;
                cin>>email;

                Contact contact(firstname , lastname , address, city, state, zip, phonenumber, email);
                addressbooks[addressbookname].addcontact(contact);
            } else {
                cout << "Address Book does not exist" << endl;
            }
            break;
        }
        case 3: {
            string addressbookname;
            cout<<"Enter the name of the addressbook"<<endl;
            cin>>addressbookname;

            if(addressbooks.find(addressbookname) != addressbooks.end()){
                for(const auto& contact : addressbooks[addressbookname].contacts){
                    cout<<"Firstname: "<<contact.firstname<<endl;
                    cout<<"Lastname: "<<contact.lastname<<endl;
                    cout<<"Address: "<<contact.address<<endl;
                    cout<<"City: "<<contact.city<<endl;
                    cout<<"State: "<<contact.state<<endl;
                    cout<<"ZIP: "<<contact.zip<<endl;
                    cout<<"Phone Number: "<<contact.phonenumber<<endl;
                    cout<<"Email: "<<contact.email<<endl;
                    cout<<"--------------------------"<<endl;
                }
            } else {
                cout << "Address Book does not exist" << endl;
            }
            break;
        }
        case 4: {
            string addressbookname;
            cout<<"Enter the name of the addressbook"<<endl;
            cin>>addressbookname;

            if(addressbooks.find(addressbookname) != addressbooks.end()){
                string firstname, lastname;
                cout<<"Enter firstname of the contact to edit: "<<endl;
                cin>>firstname;
                cout<<"Enter lastname of the contact to edit: "<<endl;
                cin>>lastname;
                addressbooks[addressbookname].editcontact(firstname, lastname);
            } else {
                cout << "Address Book does not exist" << endl;
            }
            break;
        }
        case 5: {
            string addressbookname;
            cout<<"Enter the name of the addressbook"<<endl;
            cin>>addressbookname;

            if(addressbooks.find(addressbookname) != addressbooks.end()){
                string firstname, lastname;
                cout<<"Enter firstname of the contact to delete: "<<endl;
                cin>>firstname;
                cout<<"Enter lastname of the contact to delete: "<<endl;
                cin>>lastname;
                addressbooks[addressbookname].deletecontact(firstname, lastname);
            } else {
                cout << "Address Book does not exist" << endl;
            }
            break;
        }
        case 6:
            cout<<"Exiting Address Book Program."<<endl;
            break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    return 0;
}
