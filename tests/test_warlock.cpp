#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../unit/Demon.h"
#include "../spellcaster/Warlock.h"
#include "../spell/Heal.h"

TEST_CASE( "Test Warlock class" ) {
    Soldier* soldier = new Soldier("Soldier", 150, 20);
    Warlock* warlock = new Warlock("Warlock", 100, 10, 150);

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    REQUIRE( warlock->getTitle() == "Warlock" );
    REQUIRE( warlock->getHitPoints() == 100 );
    REQUIRE( warlock->getHitPointsLimit() == 100 );
    REQUIRE( warlock->getDamage() == 10 );
    REQUIRE( warlock->getMana() == 150 );
    REQUIRE( warlock->getManaLimit() == 150 );
    REQUIRE( warlock->getBattleMagician() == true );

    warlock->attack(soldier);
    REQUIRE( warlock->getHitPoints() == 90 );
    REQUIRE( soldier->getHitPoints() == 140 );

    warlock->cast(warlock, soldier);
    REQUIRE( soldier->getHitPoints() == 125 );
    REQUIRE( warlock->getHitPoints() == 90 );
    REQUIRE( warlock->getMana() == 120 );

    warlock->changeSpell(HEAL);
    warlock->cast(warlock, soldier);
    REQUIRE( soldier->getHitPoints() == 140 );
    REQUIRE( warlock->getHitPoints() == 90 );
    REQUIRE( warlock->getMana() == 90 );

    warlock->cast(warlock, soldier);
    warlock->cast(warlock, soldier);
    warlock->cast(warlock, soldier);

    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( warlock->getHitPoints() == 90 );
    REQUIRE( warlock->getMana() == 0 );

    try {
        warlock->cast(warlock, soldier);
    } catch (OutOfManaException obj) {
        REQUIRE( warlock->getMana() == 0 );
    }

    warlock->addMana(80);
    REQUIRE( warlock->getMana() == 80 );

    warlock->addMana(200);
    REQUIRE( warlock->getMana() == 150 );

//    warlock->summonDemon(warlock);
    Demon* demon = warlock->summonDemon(warlock);

//    REQUIRE( demon->getTitle() == "Demon" );
    REQUIRE( demon->getHitPoints() == 100 );
    REQUIRE( warlock->summonDemon(warlock)->getHitPointsLimit() == 100 );
    REQUIRE( warlock->summonDemon(warlock)->getDamage() == 10 );
}
