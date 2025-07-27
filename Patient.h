#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>
#include "Organ.h"
#include "Condition.h"
#include "Treatment.h"

class Patient {
private:
    std::string name;
    int age;

    std::vector<Organ> organs;
    std::vector<Condition> conditions;
    std::vector<Treatment> treatments;

public:
    Patient(std::string name, int age);

    void addOrgan(const Organ& organ);
    void addCondition(const Condition& condition);
    void addTreatment(const Treatment& treatment);

    void simulateMonth(float dietQuality, float exerciseLevel, float sleepHours, float stressLevel);

    void printHealthReport() const;
};

#endif
