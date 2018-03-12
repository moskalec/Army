#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spellcaster/Wizard.h"
#include "../unit/Berserker.h"

TEST_CASE( "Test Berserker class" ) {
    Wizard* wizard = new Wizard("Wizard", 100, 10, 150);
    Berserker* berserker = new Berserker("Berserker", 200, 30);

    wizard->attack(berserker);
    REQUIRE( wizard->getHitPoints() == 85 );
    REQUIRE( berserker->getHitPoints() == 190 );

    wizard->cast(berserker);
    REQUIRE( berserker->getHitPoints() == 190 );
    REQUIRE( wizard->getHitPoints() == 85 );
    REQUIRE( wizard->getMana() == 120 );
}
