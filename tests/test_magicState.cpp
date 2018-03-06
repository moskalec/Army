#include "catch.hpp"
#include "../state/MagicState.h"

TEST_CASE( "Test MagicState class" ) {
    MagicState* state = new MagicState(150);

    REQUIRE( state->getMana() == 150 );
    REQUIRE( state->getManaLimit() == 150 );
    
    SECTION( "MagicState::spendMana tests" ) {
        int cost = 10;
        int iterations = state->getMana() / cost;

        for ( int i = 1; i <= iterations; i++ ) {
            state->spendMana(cost);
            int expectedMana = state->getManaLimit() - cost * i;
            REQUIRE( state->getMana() == expectedMana );
        }

        try {
            state->spendMana(cost);
        } catch ( OutOfManaException obj ) {
            REQUIRE( state->getMana() == 0 );
        }
    }
    
    SECTION( "MagicState::addMana tests" ) {
        state->spendMana(50);
        REQUIRE( state->getMana() == 100 );

        state->addMana(40);
        REQUIRE( state->getMana() == 140 );

        state->addMana(10);
        REQUIRE( state->getMana() == 150 );

        state->addMana(10);
        REQUIRE( state->getMana() == 150 );
    }
}
