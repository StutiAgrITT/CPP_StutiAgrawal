#ifndef ENUMS_H
#define ENUMS_H

enum WelcomeMenuChoice {
    WELCOME_SIGN_IN = 1,
    WELCOME_SIGN_UP,
    WELCOME_EXIT
};

enum MainMenuChoice {
    MAIN_CREATE_POST = 1,
    MAIN_FEED,
    MAIN_MY_PROFILE,
    MAIN_SEARCH_USER,
    MAIN_SIGN_OUT
};

enum FeedMenuChoice {
    FEED_NEXT = 1,
    FEED_PREVIOUS,
    FEED_TOGGLE_LIKE,
    FEED_VIEW_LIKERS,
    FEED_VIEW_PROFILE,
    FEED_BACK
};

#endif
