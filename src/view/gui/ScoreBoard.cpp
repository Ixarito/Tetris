#include <QVBoxLayout>
#include <QHBoxLayout>
#include "ScoreBoard.h"

namespace tetris::view::gui {

	ScoreBoard::ScoreBoard(QWidget *parent): QWidget(parent) {
		QString style = "font-weight: bold; font-size: 16pt; color: #f5f5f5;";

		auto datasLayout = new QVBoxLayout(this);

		auto scoreLayout = new QHBoxLayout();
		auto levelLayout = new QHBoxLayout();
		auto clearedLinesLayout = new QHBoxLayout();

		auto scoreLabel = new QLabel("Score:", this);
		auto levelLabel = new QLabel("Level:", this);
		auto clearedLinesLabel = new QLabel("Full Lines:", this);

		scoreValue = new QLabel(this);
		levelValue = new QLabel(this);
		clearedLinesValue = new QLabel(this);

		scoreLabel->setStyleSheet(style);
		levelLabel->setStyleSheet(style);
		clearedLinesLabel->setStyleSheet(style);
		scoreValue->setStyleSheet(style);
		levelValue->setStyleSheet(style);
		clearedLinesValue->setStyleSheet(style);

		scoreLayout->addWidget(scoreLabel);
		scoreLayout->addWidget(scoreValue);

		levelLayout->addWidget(levelLabel);
		levelLayout->addWidget(levelValue);

		clearedLinesLayout->addWidget(clearedLinesLabel);
		clearedLinesLayout->addWidget(clearedLinesValue);

		datasLayout->addLayout(scoreLayout);
		datasLayout->addLayout(levelLayout);
		datasLayout->addLayout(clearedLinesLayout);
	}

	void ScoreBoard::updateScore(const model::Game & game) const{
		scoreValue->setText(QString::number(game.getScore()));
		levelValue->setText(QString::number(game.getLevel()));
		clearedLinesValue->setText(QString::number(game.getNbClearedLines()));
	}

} // namespace tetris::view::gui