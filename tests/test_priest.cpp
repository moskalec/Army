#include "catch.hpp"
#include "../unit/Vampire.h"
#include "../spellcaster/Priest.h"
#include "../spell/Heal.h"

TEST_CASE( "Test Healer class" ) {
    Priest* priest = new Priest("Priest", 100, 10, 150);
    Vampire* vampire = new Vampire("Vampire", 100, 20);

    REQUIRE( priest->getTitle() == "Priest" );
    REQUIRE( priest->getHitPoints() == 100 );
    REQUIRE( priest->getHitPointsLimit() == 100 );
    REQUIRE( priest->getDamage() == 10 );
    REQUIRE( priest->getMana() == 150 );
    REQUIRE( priest->getManaLimit() == 150 );
    REQUIRE( priest->getBattleMagician() == false );

    REQUIRE( vampire->getTitle() == "Vampire" );
    REQUIRE( vampire->getHitPoints() == 100 );
    REQUIRE( vampire->getHitPointsLimit() == 100 );
    REQUIRE( vampire->getDamage() == 20 );
    REQUIRE( vampire->isVampire() == true );

    priest->attack(vampire);
    REQUIRE( priest->getHitPoints() == 90 );
    REQUIRE( vampire->getHitPoints() == 92 );

    priest->cast(priest, vampire);
    REQUIRE( vampire->getHitPoints() == 32 );
    REQUIRE( priest->getHitPoints() == 90 );
    REQUIRE( priest->getMana() == 120 );

    priest->changeSpell(HEAL);
    priest->cast(priest, vampire);
    REQUIRE( vampire->getHitPoints() == 62 );
    REQUIRE( priest->getHitPoints() == 90 );
    REQUIRE( priest->getMana() == 90 );

    priest->cast(priest, vampire);
    priest->cast(priest, vampire);
    priest->cast(priest, vampire);

    REQUIRE( vampire->getHitPoints() == 100 );
    REQUIRE( priest->getHitPoints() == 90 );
    REQUIRE( priest->getMana() == 0 );
}
