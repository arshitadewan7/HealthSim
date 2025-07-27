#include "Patient.h"
#include <iostream>

Patient::Patient(std::string name, int age)
    : name(name), age(age) {}

void Patient::addOrgan(Organ* organ) {
    organs.push_back(organ);
}

void Patient::addCondition(const Condition& condition) {
    conditions.push_back(condition);
}

void Patient::addTreatment(const Treatment& treatment) {
    treatments.push_back(treatment);
}

void Patient::simulateMonth(float dietQuality, float exerciseLevel, float sleepHours, float stressLevel) {
    // Simulate condition progression
    for (auto& condition : conditions) {
        // Increase severity based on poor lifestyle factors (example logic)
        float riskFactor = (1.0f - dietQuality) + (1.0f - exerciseLevel) + (stressLevel / 10.0f);
        condition.progress(riskFactor * 2.0f);

        // Condition affects organs
        condition.affectOrgans();
    }

    // Apply treatments to organs to heal
    for (auto& treatment : treatments) {
        treatment.applyTreatment(organs);  // Now vector<Organ*> matches
    }

    // Lifestyle impact: healthier lifestyle heals organs a bit
    float lifestyleScore = (dietQuality + exerciseLevel + (sleepHours / 8.0f)) / 3.0f;
    for (auto& organ : organs) {
        organ->heal(lifestyleScore * 5.0f); // Use pointer dereference
    }
}

void Patient::printHealthReport() const {
    std::cout << "Health Report for " << name << " (Age " << age << "):\n";
    for (const auto& organ : organs) {
        std::cout << "- " << organ->getName() << ": " << organ->getHealthScore() << "/100 health\n";
    }
    for (const auto& condition : conditions) {
        std::cout << "- Condition " << condition.getName() << " severity: " << condition.getSeverity() << "/100\n";
    }
    std::cout << std::endl;
}
