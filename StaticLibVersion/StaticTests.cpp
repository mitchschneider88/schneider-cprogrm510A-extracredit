#include "TestHarness.h"
#include "DerivedShape.h"


TEST(LoadStaticLib, StaticLibs)
{
    int i;

    std::stringstream ss;

    Rectangle rect ({1.5,1.2}, {2.2,2.3}, ss);

    i = rect.meaningOfLife();

    CHECK_EQUAL(42, i);

    CHECK_EQUAL(Color::Red, rect.getColor());

    Shape* s;

    s = &rect;

    i = s->meaningOfLife();

    CHECK_EQUAL(42, i);

    CHECK_EQUAL(Color::Red, s->getColor());
}
