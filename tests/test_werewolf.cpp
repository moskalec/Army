#include "catch.hpp"
#include "../unit/Werewolf.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Werewolf class" ) {
    Werewolf* werewolf = new Werewolf("Werewolf", 100, 20);

    REQUIRE( werewolf->getTitle() == "Werewolf" );
    REQUIRE( werewolf->getHitPoints() == 100 );
    REQUIRE( werewolf->getHitPointsLimit() == 100 );
    REQUIRE( werewolf->getDamage() == 20 );

    SECTION( "Werewolf::takeDamage tests" ) {
        int damage = 10;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        try {
            werewolf->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }

        try {
            werewolf->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeMagicDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        try {
            werewolf->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }

        try {
            werewolf->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }
    SECTION( "Werewolf::addHitPoints tests" ) {
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoints() == 50 );

        werewolf->addHitPoints(40);
        REQUIRE( werewolf->getHitPoints() == 90 );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == 100 );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == 100 );
    }
    SECTION( "Werewolf::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getDamage() == 20 );

        werewolf->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 130 );
        REQUIRE( werewolf->getHitPoints() == 90 );

        werewolf->attack(enemy);
        werewolf->attack(enemy);
        werewolf->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 70 );
        REQUIRE( werewolf->getHitPoints() == 60 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            werewolf->attack(enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( werewolf->getHitPoints() == 60 );
        }

        try {
            enemy->attack(werewolf);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( werewolf->getHitPoints() == 60 );
        }

    }

}
