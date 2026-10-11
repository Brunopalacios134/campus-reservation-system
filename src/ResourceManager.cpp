#include "ResourceManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void mergeResources(vector<Resource>& resources, int left, int mid, int right, bool byType){
    vector<Resource> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right){
        string leftValue = byType
            ? resources[i].getResourceType()
            : resources[i].getResourceName();

        string rightValue = byType
            ? resources[j].getResourceType()
            : resources[j].getResourceName();

        if (leftValue <= rightValue){
            temp.push_back(resources[i]);
            i++;
        }
        else{
            temp.push_back(resources[j]);
            j++;
        }
    }
    while (i <= mid){
        temp.push_back(resources[i]);
        i++;
    }
    while (j <= right){
        temp.push_back(resources[j]);
        j++;
    }
    for (int k = 0; k < static_cast<int>(temp.size()); k++){
        resources[left + k] = temp[k];
    }
}
void mergeSortResources(vector<Resource>& resources, int left, int right, bool byType){
    if (left >= right){
        return;
    }
    int mid = left + (right - left)/2;

    mergeSortResources(resources,left,mid,byType);
    mergeSortResources(resources, mid + 1,right,byType);

    mergeResources(resources, left, mid, right,byType);
}

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

        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, type, '|');
        getline(ss, status, '|');

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

void ResourceManager::sortByName(){
    if(!resources.empty()){
        mergeSortResources(resources, 0, static_cast<int>(resources.size())-1,false);
    }
}

void ResourceManager::sortByType(){
    if (!resources.empty()){
        mergeSortResources(resources, 0, static_cast<int>(resources.size()) -1, true);
    }
}
int ResourceManager::getResourceCount() const {
    return resources.size();
}
