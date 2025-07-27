#ifndef CONDITION_H
#define CONDITION_H

#include <string>
#include <vector>
#include "Organ.h"

class Condition {
private:
    std::string name;
    float severity;           // 0 (none) to 100 (severe)
    std::vector<Organ*> affectedOrgans;

public:
    Condition(std::string name, float severity = 0.0f);

    void addAffectedOrgan(Organ* organ);
    void progress(float amount);  // condition worsens
    void treat(float amount);     // condition improves

    std::string getName() const;
    float getSeverity() const;
    void affectOrgans();
};

#endif
