#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

class ResourceManager {
private:
    vector<Resource> resources;

public:
    bool loadFromFile(string filename);

    void displayAll() const;

    void displayAvailability() const;

    Resource* search(string resourceID);

    void sortByName();

    void sortByType();

    int getResourceCount() const;
};

#endif