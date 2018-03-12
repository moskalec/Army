#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spellcaster/Wizard.h"

TEST_CASE( "Test Wizard class" ) {
    Soldier* soldier = new Soldier("Soldier", 150, 20);
    Wizard* wizard = new Wizard("Wizard", 100, 10, 150);

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    REQUIRE( wizard->getTitle() == "Wizard" );
    REQUIRE( wizard->getHitPoints() == 100 );
    REQUIRE( wizard->getHitPointsLimit() == 100 );
    REQUIRE( wizard->getDamage() == 10 );
    REQUIRE( wizard->getMana() == 150 );
    REQUIRE( wizard->getManaLimit() == 150 );

    wizard->attack(soldier);
    REQUIRE( wizard->getHitPoints() == 90 );
    REQUIRE( soldier->getHitPoints() == 140 );

    wizard->cast(soldier);
    REQUIRE( soldier->getHitPoints() == 110 );
    REQUIRE( wizard->getHitPoints() == 90 );
    REQUIRE( wizard->getMana() == 120 );

    wizard->changeSpell(HEAL);
    wizard->cast(soldier);
    REQUIRE( soldier->getHitPoints() == 140 );
//    REQUIRE( wizard->getHitPoints() == 90 );
//    REQUIRE( wizard->getMana() == 90 );

//    wizard->cast(soldier);
//    wizard->cast(soldier);
//    wizard->cast(soldier);

//    REQUIRE( soldier->getHitPoints() == 150 );
//    REQUIRE( wizard->getHitPoints() == 90 );
//    REQUIRE( wizard->getMana() == 0 );
//
//    try {
//        wizard->cast(soldier);
//    } catch (OutOfManaException obj) {
//        REQUIRE( wizard->getMana() == 0 );
//    }
//
//    wizard->addMana(80);
//    REQUIRE( wizard->getMana() == 80 );
//
//    wizard->addMana(200);
//    REQUIRE( wizard->getMana() == 150 );
}
