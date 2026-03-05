#include "Application.h"
#include "Logger.h"
#include "Utility.h"
#include "AudioPlayer.h"
#include "PlaylistManager.h"

int main() {
    ILogger* logger = new Logger();
    IUtility* utility = new Utility(logger);
    IAudioPlayer* audioPlayer = new AudioPlayer();
    PlaylistManager* manager = new PlaylistManager(logger);

    Application app(manager, audioPlayer, logger, utility);
    app.run();

    delete manager;
    delete audioPlayer;
    delete utility;
    delete logger;

    return 0;
}