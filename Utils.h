#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <algorithm>

bool validateUniqueID(int id, const std::vector<int>& existingIDs);
bool validateUniqueName(const std::string& name, const std::vector<std::string>& existingNames);

#endif // UTILS_H
