#include "Game.h"
#include <QTimer>

namespace tetris::controller::gui {

    class GameController : public QObject {
        Q_OBJECT
    public:
        GameController(model::Game & game);

        void startGame();

        void stopGame();

    public slots:
        void movePiece();

    private:
        model::Game & game;
        QTimer *timer;
    };

} // namespace tetris::controller::gui