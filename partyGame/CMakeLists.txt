project(partyGame)

add_executable(${PROJECT_NAME}.elf


        src/main.cpp
        src/Game/Game.cpp
        src/Game/Game.h
        src/Game/Speler.cpp
        src/Game/Speler.h

        screens/OtherScreens/MainMenuScreen.cpp
        screens/OtherScreens/MainMenuScreen.h
        screens/OtherScreens/AboutScreen.cpp
        screens/OtherScreens/AboutScreen.h
        screens/GameScreen/GameScreen.cpp
        screens/GameScreen/GameScreen.h

        backgrounds/standard/gras.c
        backgrounds/standard/gras.h
        backgrounds/standard/grasBackground.h
        backgrounds/gameScreen/transparantAndRedMap.h


        Sprites/wit_spook_1.h
        Sprites/wit_spook_1.c
        Sprites/wit_spook_2.h
        Sprites/wit_spook_2.c

        Sprites/redEnemyCenter.h
        Sprites/greenEnemyCenter.h
        Sprites/blueEnemyCenter.h
        Sprites/redEnemyCenter.c
        Sprites/greenEnemyCenter.c
        Sprites/blueEnemyCenter.c

        Sprites/pijl.h
        Sprites/dobbelsteen.h
        Sprites/box.h
        Sprites/pijl.c
        Sprites/dobbelsteen.c
        Sprites/box.c

        Sprites/red_stone_with_border.h
        Sprites/green_stone_with_border.h
        Sprites/blue_stone_with_border.h
        Sprites/red_stone_with_border.c
        Sprites/green_stone_with_border.c
        Sprites/blue_stone_with_border.c

        Sprites/alleKleuren.h
        Sprites/alleKleuren.c

        Sprites/shared.h
        Sprites/shared.c

        Sprites/ghost_family_moving1.c
        Sprites/ghost_family_moving1.h
        Sprites/ghost_family_moving2.c
        Sprites/ghost_family_moving2.h
        Sprites/ghost_family_moving3.c
        Sprites/ghost_family_moving3.h
        Sprites/ghost_family_moving4.c
        Sprites/ghost_family_moving4.h
        Sprites/sharedEndScreen.h
        Sprites/sharedEndScreen.c

        Sprites/ghost_family_1.c
        Sprites/ghost_family_1.h
        Sprites/ghost_family_2.c
        Sprites/ghost_family_2.h
        Sprites/ghost_family_3.c
        Sprites/ghost_family_3.h
        Sprites/ghost_family_4.c
        Sprites/ghost_family_4.h
        Sprites/sharedGhost.h
        Sprites/sharedGhost.c
        Sprites/pijlEnd.h
        Sprites/pijlEnd.c


        src/Game/Game.cpp src/Game/Game.h src/Game/Speler.cpp src/Game/Speler.h screens/GameScreen/GameScreen.cpp screens/GameScreen/GameScreen.h src/Minigames/Minigame1.cpp src/Minigames/Minigame1.h src/Minigames/Minigame2.cpp src/Minigames/Minigame2.h screens/MinigameScreens/MinigameScreen.cpp screens/MinigameScreens/MinigameScreen.h screens/OtherScreens/EndScreen.cpp screens/OtherScreens/EndScreen.h screens/OtherScreens/PlayerSelectScreen.cpp screens/OtherScreens/PlayerSelectScreen.h src/Minigames/Minigame.cpp src/Minigames/Minigame.h src/Minigames/Minigame3.cpp src/Minigames/Minigame3.h screens/MinigameScreens/Minigame1Screen.cpp screens/MinigameScreens/Minigame1Screen.h screens/MinigameScreens/Minigame2Screen.cpp screens/MinigameScreens/Minigame2Screen.h screens/MinigameScreens/Minigame3Screen.cpp screens/MinigameScreens/Minigame3Screen.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )