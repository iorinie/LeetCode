#include <vector>

using namespace std;

#ifndef VERRIFYPOSTORDER_H

#define VERRIFYPOSTORDER_H

bool verifyPostorder(vector<int>& postorder);

bool isSubsquenceBTS(vector<int>& postorder, int startIdx, int endIdx, int rootIdx);

#endif // !VERRIFYPOSTORDER_H
