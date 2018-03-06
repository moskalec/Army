#include "catch.hpp"
#include "../unit/Soldier.h"
#include "../unit/Rogue.h"
#include "../unit/Vampire.h"


TEST_CASE( "Test Vampire class" ) {
    Vampire* vampire = new Vampire("Vampire", 100, 20);

    REQUIRE( vampire->getTitle() == "Vampire" );
    REQUIRE( vampire->getHitPoints() == 100 );
    REQUIRE( vampire->getHitPointsLimit() == 100 );
    REQUIRE( vampire->getDamage() == 20 );

    SECTION( "Vampire::takeDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }

        try {
            vampire->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeMagicDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }

        try {
            vampire->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }
    SECTION( "vampire::addHitPoints tests" ) {
        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoints() == 50 );

        vampire->addHitPoints(40);
        REQUIRE( vampire->getHitPoints() == 90 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == 100 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == 100 );
    }
    SECTION( "vampire::addHitPoints while attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( vampire->getHitPoints() == 100 );
        REQUIRE( enemy->getHitPoints() == 150 );

        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoints() == 50 );

        vampire->attack(enemy);
        REQUIRE( vampire->getHitPoints() == 44 );
        REQUIRE( enemy->getHitPoints() == 130 );
    }
    SECTION( "Vampire::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getDamage() == 20 );

        vampire->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 130 );
        REQUIRE( vampire->getHitPoints() == 94 );

        vampire->attack(enemy);
        vampire->attack(enemy);
        vampire->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 70 );
        REQUIRE( vampire->getHitPoints() == 76 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            vampire->attack(enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( vampire->getHitPoints() == 76 );
        }

        try {
            enemy->attack(vampire);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( vampire->getHitPoints() == 76 );
        }

    }

}
