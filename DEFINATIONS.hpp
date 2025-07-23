#pragma once
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0   



#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background2.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/sky1.png"   //file path for main menu
#define GAME_BACKGROUND_FILEPATH "Resources/res/sky1.png"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/sky1.png"
#define GAME_TITLE_FILEPATH "Resources/res/title1.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton2.png"
#define PIPE_UP_FILEPATH  "Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH  "Resources/res/PipeDown.png"
#define LAND_FILEPATH "Resources/res/Land.png"
#define SCORING_PIPE_FILEPATH "Resources/res/invisibleScoringPipe.png"
#define FLAPPY_FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

#define GAME_OVER_TITLE_FILEPATH "Resources/res/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "Resources/res/Game-Over-Body.png"
#define RETRY_BUTTON_FILEPATH "Resources/res/RetryButton.png"
#define HIGH_SCORE_TEXT_FILEPATH "Resources/HighScore.txt"

#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"


#define BIRD_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "Resources/res/bird-04.png"

#define PIPE_MOVEMENT_SPEED 200.0f //PIPE SPEED
#define PIPE_SPAWN_FREQUENCY 2.50f  //Sets time interval for the pipe spawn
#define BIRD_ANIMATION_DURATION 0.4f //sets the time interval for the frame change

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.4f
#define ROTATION_SPEED 100.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f

enum GameStates
{
    eReady,
    ePlaying,
    eGameOver
};

