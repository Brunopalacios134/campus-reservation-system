#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

bool ResourceManager::loadFromFile(string filename) {

    ifstream file(filename);

    if (!file) {
        cout << "Unable to open resource file." << endl;
        return false;
    }

    string line;

    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        stringstream ss(line);

        string id;
        string name;
        string type;
        string status;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, type, ',');
        getline(ss, status, ',');

        bool available =
            (status == "Available");

        resources.push_back(
            Resource(id, name, type, available)
        );
    }

    file.close();

    return true;
}

void ResourceManager::displayAll() const {

    if (resources.empty()) {
        cout << "No resources found." << endl;
        return;
    }

    cout << "\nAll Resources:\n";

    for (const auto& resource : resources) {
        resource.display();
    }
}

void ResourceManager::displayAvailability() const {

    cout << "\nResource Availability:\n";

    for (const auto& resource : resources) {

        cout << resource.getResourceID()
             << " - "
             << resource.getResourceName()
             << ": "
             << (resource.isAvailable()
                 ? "Available"
                 : "Reserved")
             << endl;
    }
}

Resource* ResourceManager::search(string resourceID) {

    for (auto& resource : resources) {

        if (resource.getResourceID() == resourceID) {
            return &resource;
        }
    }

    return nullptr;
}

void ResourceManager::sortByName() {

    sort(resources.begin(),
         resources.end(),
         [](const Resource& a, const Resource& b) {

             return a.getResourceName()
                  < b.getResourceName();
         });
}

void ResourceManager::sortByType() {

    sort(resources.begin(),
         resources.end(),
         [](const Resource& a, const Resource& b) {

             return a.getResourceType()
                  < b.getResourceType();
         });
}

int ResourceManager::getResourceCount() const {
    return resources.size();
}