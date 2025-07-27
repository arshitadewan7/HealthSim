#ifndef TREATMENT_H
#define TREATMENT_H

#include <string>
#include <vector>
#include "Organ.h"

class Treatment {
private:
    std::string name;
    float effectiveness;  // 0 to 100

public:
    Treatment(std::string name, float effectiveness = 50.0f);

    void applyTreatment(std::vector<Organ*>& organs);

    std::string getName() const;
    float getEffectiveness() const;
};

#endif
