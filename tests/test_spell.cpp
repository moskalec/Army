#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../spell/FireBall.h"
#include "../spell/Heal.h"
#include "../spellcaster/Wizard.h"

TEST_CASE( "Test spell classes" ) {
    Wizard* wizard = new Wizard("Wizard", 100, 10, 150);
    Soldier* soldier = new Soldier("Soldier", 150, 20);

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getDamage() == 20 );

    FireBall* fb = new FireBall(30, 30);

    REQUIRE( fb->getActionPoints() == 30 );
    REQUIRE( fb->getCost() == 30 );

    Heal* heal = new Heal(30, 30);

    REQUIRE( heal->getActionPoints() == 30 );
    REQUIRE( heal->getCost() == 30 );

    fb->action(wizard, soldier);

    REQUIRE( soldier->getHitPoints() == 120 );

    heal->action(wizard, soldier);

    REQUIRE( soldier->getHitPoints() == 135 );
}
