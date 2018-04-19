#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spellcaster/Necromancer.h"
#include "../spell/Heal.h"

TEST_CASE( "Test Necromancer class" ) {
    Soldier* soldier = new Soldier("Soldier", 150, 20);
    Necromancer* necromancer = new Necromancer("Necromancer", 100, 10, 150);

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    REQUIRE( necromancer->getTitle() == "Necromancer" );
    REQUIRE( necromancer->getHitPoints() == 100 );
    REQUIRE( necromancer->getHitPointsLimit() == 100 );
    REQUIRE( necromancer->getDamage() == 10 );
    REQUIRE( necromancer->getMana() == 150 );
    REQUIRE( necromancer->getManaLimit() == 150 );
    REQUIRE( necromancer->getBattleMagician() == true );

    necromancer->attack(soldier);
    REQUIRE( necromancer->getHitPoints() == 90 );
    REQUIRE( soldier->getHitPoints() == 140 );

    necromancer->cast(necromancer, soldier);
    REQUIRE( soldier->getHitPoints() == 110 );
    REQUIRE( necromancer->getHitPoints() == 90 );
    REQUIRE( necromancer->getMana() == 120 );

    necromancer->changeSpell(HEAL);
    necromancer->cast(necromancer, soldier);
    REQUIRE( soldier->getHitPoints() == 125 );
    REQUIRE( necromancer->getHitPoints() == 90 );
    REQUIRE( necromancer->getMana() == 90 );

    necromancer->cast(necromancer, soldier);
    necromancer->cast(necromancer, soldier);
    necromancer->cast(necromancer, soldier);

    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( necromancer->getHitPoints() == 90 );
    REQUIRE( necromancer->getMana() == 0 );

    try {
        necromancer->cast(necromancer, soldier);
    } catch (OutOfManaException obj) {
        REQUIRE( necromancer->getMana() == 0 );
    }

    necromancer->addMana(80);
    REQUIRE( necromancer->getMana() == 80 );

    necromancer->addMana(200);
    REQUIRE( necromancer->getMana() == 150 );
    necromancer->addHitPoints(10);
    REQUIRE( necromancer->getHitPoints() == 100 );

    SECTION( "Necromancer drain hit points test" ) {
        Soldier* soldier = new Soldier("Soldier", 150, 20);
        Necromancer* necromancer = new Necromancer("Necromancer", 100, 10, 150);

        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( necromancer->getHitPoints() == 100 );

        necromancer->attack(soldier);
        REQUIRE( soldier->getHitPoints() == 140 );
        necromancer->cast(necromancer, soldier);
        REQUIRE( soldier->getHitPoints() == 110 );
        necromancer->cast(necromancer, soldier);
        necromancer->cast(necromancer, soldier);
        necromancer->cast(necromancer, soldier);
        necromancer->cast(necromancer, soldier);
        REQUIRE( soldier->getHitPoints() == 0 );
        try {
            soldier->attack(necromancer);
        } catch (OutOfHitPointsException obj) {
            REQUIRE( necromancer->getHitPoints() == 100 );
        }
        REQUIRE( necromancer->getHitPoints() == 100 );
    }
}
