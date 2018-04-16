#include "catch.hpp"
#include "../unit/Demon.h"

TEST_CASE( "Test Demon class" ) {
    Soldier* owner = new Soldier("Owner", 150, 20);
    Demon* demon = new Demon(owner, "Demon", 150, 20);
    Soldier* enemy = new Soldier("Enemy", 150, 20);

    REQUIRE( demon->getTitle() == "Demon" );
    REQUIRE( demon->getHitPoints() == 150 );
    REQUIRE( demon->getHitPointsLimit() == 150 );
    REQUIRE( demon->getDamage() == 20 );

    SECTION( "Demon::takeDamage tests" ) {
        int damage = 10;
        int iterations = demon->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            demon->takeDamage(damage);
            int expectedHP = demon->getHitPointsLimit() - damage * i;
            REQUIRE( demon->getHitPoints() == expectedHP );
        }

        try {
            demon->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( demon->getHitPoints() == 0 );
        }

        try {
            demon->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( demon->getHitPoints() == 0 );
        }
    }

    SECTION( "Demon::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = demon->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            demon->takeMagicDamage(damage);
            int expectedHP = demon->getHitPointsLimit() - damage * i;
            REQUIRE( demon->getHitPoints() == expectedHP );
        }

        try {
            demon->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( demon->getHitPoints() == 0 );
        }

        try {
            demon->addHitPoints(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( demon->getHitPoints() == 0 );
        }
    }
    SECTION( "Demon::addHitPoints tests" ) {
        demon->takeDamage(50);
        REQUIRE( demon->getHitPoints() == 100 );

        demon->addHitPoints(40);
        REQUIRE( demon->getHitPoints() == 140 );

        demon->addHitPoints(10);
        REQUIRE( demon->getHitPoints() == 150 );

        demon->addHitPoints(10);
        REQUIRE( demon->getHitPoints() == 150 );
    }
    SECTION( "Demon::attack tests" ) {

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getDamage() == 20 );

        REQUIRE( owner->getTitle() == "Owner" );
        REQUIRE( owner->getHitPoints() == 150 );
        REQUIRE( owner->getHitPointsLimit() == 150 );
        REQUIRE( owner->getDamage() == 20 );

        demon->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 130 );
        REQUIRE( demon->getHitPoints() == 140 );

        demon->attack(enemy);
        demon->attack(enemy);
        demon->attack(enemy);

        REQUIRE( enemy->getHitPoints() == 70 );
        REQUIRE( demon->getHitPoints() == 110 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            demon->attack(enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( demon->getHitPoints() == 110 );
        }

        try {
            enemy->attack(demon);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoints() == 0 );
            REQUIRE( demon->getHitPoints() == 110 );
        }

        try {
            demon->attack(owner);
        } catch ( UnitCantAttackHisOwnerException obj ) {
            REQUIRE( owner->getHitPoints() == 150 );
            REQUIRE( demon->getHitPoints() == 110 );
        }

    }

}
