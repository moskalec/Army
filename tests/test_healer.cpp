#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spellcaster/Healer.h"
#include "../spell/Heal.h"

TEST_CASE( "Test Priest class" ) {
    Soldier* soldier = new Soldier("Soldier", 150, 20);
    Healer* healer = new Healer("Healer", 100, 10, 150);

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    REQUIRE( healer->getTitle() == "Healer" );
    REQUIRE( healer->getHitPoints() == 100 );
    REQUIRE( healer->getHitPointsLimit() == 100 );
    REQUIRE( healer->getDamage() == 10 );
    REQUIRE( healer->getMana() == 150 );
    REQUIRE( healer->getManaLimit() == 150 );
    REQUIRE( healer->getBattleMagician() == false );

    healer->attack(soldier);
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( soldier->getHitPoints() == 140 );

    healer->cast(healer, soldier);
    REQUIRE( soldier->getHitPoints() == 125 );
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( healer->getMana() == 120 );

    healer->changeSpell(new Heal(30, 30));
    healer->cast(healer, soldier);
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( healer->getMana() == 90 );

    healer->cast(healer, soldier);
    healer->cast(healer, soldier);
    healer->cast(healer, soldier);

    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( healer->getHitPoints() == 90 );
    REQUIRE( healer->getMana() == 0 );

    try {
        healer->cast(healer, soldier);
    } catch (OutOfManaException obj) {
        REQUIRE( healer->getMana() == 0 );
    }

    healer->addMana(80);
    REQUIRE( healer->getMana() == 80 );

    healer->addMana(200);
    REQUIRE( healer->getMana() == 150 );
}
