#pragma once

enum class AppState {
    Unset,
    Menu,
    Game
};

enum class GamePhaseState {
    Unset,
    Starting,
    Ending,
    Ended,
    Running,
    Paused
};