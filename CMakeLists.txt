cmake_minimum_required(VERSION 3.9)
project(army)

set(CMAKE_CXX_STANDARD 11)

add_executable(army
        ability/Ability.cpp
        ability/Ability.h
        ability/DefaultAbility.cpp
        ability/DefaultAbility.h
        ability/MagicAbility.cpp
        ability/MagicAbility.h
        ability/RogueAbility.cpp
        ability/RogueAbility.h
        spell/FireBall.cpp
        spell/FireBall.h
        spell/Heal.cpp
        spell/Heal.h
        spell/Spell.cpp
        spell/Spell.h
        spellcaster/SpellCaster.cpp
        spellcaster/SpellCaster.h
        spellcaster/Wizard.cpp
        spellcaster/Wizard.h
        state/MagicState.cpp
        state/MagicState.h
        state/State.cpp
        state/State.h
        tests/catch.hpp
        tests/test_magicState.cpp
        tests/test_main.cpp
        tests/test_rogue.cpp
        tests/test_soldier.cpp
        tests/test_spell.cpp
        tests/test_state.cpp
        tests/test_unit.cpp
        tests/test_wizard.cpp
        unit/Rogue.cpp
        unit/Rogue.h
        unit/Soldier.cpp
        unit/Soldier.h
        unit/Unit.cpp
        unit/Unit.h
        exceptions.h unit/Berserker.h unit/Berserker.cpp tests/test_berserker.cpp unit/Vampire.h unit/Vampire.cpp ability/VampireAbility.h ability/VampireAbility.cpp tests/test_vampire.cpp unit/Werewolf.h unit/Werewolf.cpp tests/test_werewolf.cpp)
