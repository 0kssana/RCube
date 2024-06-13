//
// Created by oksana on 6/13/24.
//

#ifndef RCUBE_MOCKCUBE_H
#define RCUBE_MOCKCUBE_H

#include <gmock/gmock.h>
#include "../RCube/cube.h"

class MockCube : public Cube {
public:
    MOCK_METHOD(bool, has_all_colors, (), (override));
};

#endif //RCUBE_MOCKCUBE_H
