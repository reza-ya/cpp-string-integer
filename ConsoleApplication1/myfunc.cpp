#include <vector>

namespace tools 
{
    bool isIncluded(std::vector<int> single_gooni_vector, int num_to_check) {
        for (int i = 0; i < single_gooni_vector.size(); i++) {
            if (single_gooni_vector[i] == num_to_check) {
                return true;
            }
        }
        return false;
    }

    int calculat(std::vector<int> single_gooni_vector) {

        int i = 1;
        while (true) {
            if (!isIncluded(single_gooni_vector, i)) {
                break;
            }
            else {
                i++;
            }
        };
        return i;
    };
}

