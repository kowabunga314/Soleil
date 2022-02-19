
#include "sampler.h"


Sampler sampler = Sampler();

void setup() {
    sampler.initialize(5);
}

void loop () {
    sampler.takeSample();
}
