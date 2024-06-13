#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "../RCube/cube.h"  // Включите ваш основной код

class CubeTest {
public:
    static bool testCheckMethod(Cube &cube) {
        cube.coloring(cube.left, 2);
        cube.coloring(cube.right, 3);
        cube.coloring(cube.front, 0);
        cube.coloring(cube.back, 1);
        cube.coloring(cube.up, 4);
        cube.coloring(cube.down, 5);
        return cube.check();
    }
static bool testCheckAllMethod(Cube& cube) { 
    cube.coloring(cube.left, 2);
    cube.coloring(cube.right, 3);
    cube.coloring(cube.front, 0); 
    cube.coloring(cube.back, 1);
    cube.coloring(cube.up, 4);
    cube.coloring(cube.down, 5);
    return cube.has_all_colors();
} 
};

TEST_CASE("Testing Cube::check method") {
    Cube cube;

    SUBCASE("Positive test case - All conditions met") {
        CHECK(CubeTest::testCheckMethod(cube) == true);
    }
}

TEST_CASE("Testing Cube::has all colors method") { 
    Cube cube;
    
    SUBCASE("Positive test case - All colors have") { 
        CHECK(CubeTest::testCheckMethod(cube) == true); 
    }
}
