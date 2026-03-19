#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

namespace Path {
    const std::string USERS_DIR = "users/";
}

namespace Extensions {
    const std::string TXT = ".txt";
}

namespace Files {
    const std::string PROFILE = "/profile.txt";
    const std::string POSTS = "/posts.txt";
    const std::string LIKES = "/likes.txt";
}

namespace Separator {
    const std::string POST = "---";
    const std::string FIELD = ": ";
    const std::string LIKED_BY = " ";
    const char NEWLINE_CHAR = '\n';
    const std::string DOT = ".";
    const std::string DOUBLE_DOT = "..";
    const std::string UNDERSCORE = "_";
    const std::string EMPTY_STRING = "";
}

namespace Validation {
    const std::string INVALID_CHARS = "/:*?\"<>|\\";
    const std::string WHITESPACES = " \t\n";
    const int MIN_PASSWORD_LEN = 6;
    const char BACKSPACE_CHAR  = 127;
    const char DELETE_CHAR = '\b';
    const std::string BACKSPACE_SEQ   = "\b \b";
    const int INITIAL_POST_COUNT = 0;
}

namespace Menu {
    const std::string WELCOME =
        "\n=== Mini Instagram ===\n"
        "1. Sign In\n"
        "2. Sign Up\n"
        "3. Exit\n"
        "Enter choice: ";

    const std::string MAIN =
        "\n=== Main Menu ===\n"
        "1. Create Post\n"
        "2. Feed\n"
        "3. My Profile\n"
        "4. Search User\n"
        "5. Sign Out\n"
        "Enter choice: ";

    const std::string FEED =
        "\n1. Next Post\n"
        "2. Previous Post\n"
        "3. Like / Unlike\n"
        "4. View Who Liked\n"
        "5. View Author Profile\n"
        "6. Back\n"
        "Enter choice: ";
}

namespace Prompt {
    const std::string ENTER_USERNAME = "Enter username: ";
    const std::string ENTER_PASSWORD = "Enter password: ";
    const std::string ENTER_DISPLAY_NAME = "Enter display name: ";
    const std::string ENTER_BIO = "Enter bio: ";
    const std::string ENTER_POST_TEXT = "Enter post text: ";
    const std::string ENTER_SEARCH_USER = "Enter username to search: ";
}

namespace Success {
    const std::string SIGN_UP = "Account created successfully!\n";
    const std::string SIGN_IN = "Signed in successfully!\n";
    const std::string SIGN_OUT = "Signed out successfully!\n";
    const std::string POST_CREATED = "Post created successfully!\n";
    const std::string LIKED = "Post liked!\n";
    const std::string UNLIKED = "Post unliked!\n";
}

namespace Error {
    const std::string INVALID_CHOICE = "Invalid choice! Please try again.\n";
    const std::string INVALID_INPUT = "Invalid input! Please try again.\n";
    const std::string USERNAME_TAKEN = "Username already taken!\n";
    const std::string INVALID_CREDENTIALS = "Invalid username or password!\n";
    const std::string INVALID_PASSWORD = "Password must be at least 6 characters, and contain an uppercase letter, lowercase letter, digit, and special character.\n";
    const std::string INVALID_USERNAME = "Username cannot be empty!\n";
    const std::string USER_NOT_FOUND = "User not found!\n";
    const std::string NO_POSTS = "No posts yet.\n";
    const std::string TOP_OF_FEED = "You are at the most recent post.\n";
    const std::string BOTTOM_OF_FEED = "No more posts.\n";
    const std::string FILE_OPEN_FAILED = "Failed to open file!\n";
    const std::string FILE_WRITE_FAILED = "Failed to write file!\n";
    const std::string NOT_LOGGED_IN = "No user is currently logged in.\n";
}

namespace Info {
    const std::string SEPARATOR = "========================================\n";
    const std::string WELCOME = "\nWelcome to Mini Instagram!\n";
    const std::string GOODBYE = "Goodbye!\n";
    const std::string NEWLINE = "\n";
    const std::string LIKES_LABEL = "Likes: ";
    const std::string BY = "By: ";
    const std::string AT = "At: ";
    const std::string LIKED_BY = "Liked by: ";
    const std::string POST_COUNT = "Posts: ";
    const std::string BIO = "Bio: ";
    const std::string DISPLAY_NAME = "Name: ";
}

namespace PostFields {
    const std::string POST_ID = "postId";
    const std::string AUTHOR_USERNAME = "authorUsername";
    const std::string TEXT = "text";
    const std::string TIMESTAMP = "timestamp";
    const std::string LIKE_COUNT = "likeCount";
}

namespace ProfileFields {
    const std::string USERNAME = "username";
    const std::string PASSWORD = "password";
    const std::string DISPLAY_NAME = "displayName";
    const std::string BIO = "bio";
    const std::string POST_COUNT = "postCount";
}

namespace LikeFields {
    const std::string POST_ID = "postId";
    const std::string LIKED_BY = "likedBy";
}

#endif
