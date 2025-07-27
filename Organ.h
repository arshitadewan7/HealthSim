#ifndef ORGAN_H
#define ORGAN_H

#include <string>

class Organ {
private:
    std::string name;
    float healthScore; // 0 to 100

public:
    Organ(std::string name, float healthScore = 100.0f);

    void damage(float amount);
    void heal(float amount);
    std::string getName() const;
    float getHealthScore() const;
};

#endif
