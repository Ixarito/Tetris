#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include "Observer.h"
#include <QTimer>

namespace tetris::controller::gui {

	using namespace common;

	class GameController : public QObject, Observer{
        Q_OBJECT
    public:
        GameController(model::Game & game);

        void startGame();

        void stopGame();

		void update(ActionType action, void* subject);

    public slots:
        void movePiece();

    private:
        model::Game & game;
        QTimer *timer;
    };

} // namespace tetris::controller::gui

#endif //GAMECONTROLLER_H