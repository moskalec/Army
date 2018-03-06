#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../unit/Rogue.h"


TEST_CASE( "Test Rogue class" ) {
    Rogue* rogue = new Rogue("Rogue", 150, 20);

    REQUIRE( rogue->getTitle() == "Rogue" );
    REQUIRE( rogue->getHitPoints() == 150 );
    REQUIRE( rogue->getHitPointsLimit() == 150 );
    REQUIRE( rogue->getDamage() == 20 );
    
    SECTION( "Rogue::takeDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            rogue->takeDamage(damage);
            int expectedHP = rogue->getHitPointsLimit() - damage * i;
            REQUIRE( rogue->getHitPoints() == expectedHP );
        }

        try {
            rogue->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }

        try {
            rogue->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }
    }
    
    SECTION( "Rogue::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            rogue->takeMagicDamage(damage);
            int expectedHP = rogue->getHitPointsLimit() - damage * i;
            REQUIRE( rogue->getHitPoints() == expectedHP );
        }

        try {
            rogue->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }

        try {
            rogue->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }
    }
    SECTION( "Rogue::addHitPoints tests" ) {
        rogue->takeDamage(50);
        REQUIRE( rogue->getHitPoints() == 100 );

        rogue->addHitPoints(40);
        REQUIRE( rogue->getHitPoints() == 140 );

        rogue->addHitPoints(10);
        REQUIRE( rogue->getHitPoints() == 150 );

        rogue->addHitPoints(10);
        REQUIRE( rogue->getHitPoints() == 150 );
    }
    SECTION( "Rogue::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getDamage() == 20 );

        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 130 );
        REQUIRE( rogue->getHitPoints() == 150 );

        rogue->attack(enemy);
        rogue->attack(enemy);
        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 70 );
        REQUIRE( rogue->getHitPoints() == 150 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            rogue->attack(enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( rogue->getHitPoints() == 150 );
        }

        try {
            enemy->attack(rogue);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( rogue->getHitPoints() == 150 );
        }

    }

}
