#include "Utils.h"

bool validateUniqueID(int id, const std::vector<int>& existingIDs) {
    return std::find(existingIDs.begin(), existingIDs.end(), id) == existingIDs.end();
}

bool validateUniqueName(const std::string& name, const std::vector<std::string>& existingNames) {
    return std::find(existingNames.begin(), existingNames.end(), name) == existingNames.end();
}
