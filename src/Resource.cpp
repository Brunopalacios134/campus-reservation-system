#include "Resource.h"
#include <iostream>

using namespace std;

Resource::Resource() {
    resourceID = "";
    resourceName = "";
    resourceType = "";
    available = true;
}

Resource::Resource(string id, string name, string type, bool status) {
    resourceID = id;
    resourceName = name;
    resourceType = type;
    available = status;
}

string Resource::getResourceID() const {
    return resourceID;
}

string Resource::getResourceName() const {
    return resourceName;
}

string Resource::getResourceType() const {
    return resourceType;
}

bool Resource::isAvailable() const {
    return available;
}

void Resource::setAvailability(bool status) {
    available = status;
}

void Resource::display() const {
    cout << "ID: " << resourceID
         << " | Name: " << resourceName
         << " | Type: " << resourceType
         << " | Status: "
         << (available ? "Available" : "Reserved")
         << endl;
}
