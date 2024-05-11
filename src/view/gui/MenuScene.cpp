#include <QGraphicsDropShadowEffect>
#include "MenuScene.h"

namespace tetris::view::gui {

	MenuScene::MenuScene(QWidget *parent) : QWidget(parent) {
		// Create the layout
		layout = new QVBoxLayout(this);
		layout->setSpacing(10);
		layout->setAlignment(Qt::AlignCenter);

		// Create the title
		title = new QLabel("Tetris", this);
		title->setAlignment(Qt::AlignCenter);
		title->setStyleSheet("font-size: 30px; color: #FFFFFF; font-weight: bold; margin-bottom: 20px;");
		layout->addWidget(title);

		// Create the buttons
		playButton = new QPushButton("Jouer", this);
		playButton->setStyleSheet("background-color: #1c8dd9; color: #FFFFFF; font-size: 20px; font-weight: bold; border-radius: 10px; padding: 10px 20px; margin-bottom: 20px;");
		playButton->setCursor(Qt::PointingHandCursor);
		layout->addWidget(playButton);

		quitButton = new QPushButton("Quitter", this);
		quitButton->setStyleSheet("background-color: #d9291c; color: #FFFFFF; font-size: 20px; font-weight: bold; border-radius: 10px; padding: 10px 20px;");
		quitButton->setCursor(Qt::PointingHandCursor);
		layout->addWidget(quitButton);

		// Create the game type label
		gameTypeLabel = new QLabel("Type de jeu", this);
		gameTypeLabel->setStyleSheet("color: #FFFFFF;");
		layout->addWidget(gameTypeLabel);
		gameTypeLabel->hide();

		// Create the game type combo box
		gameTypeComboBox = new QComboBox(this);
		gameTypeComboBox->addItem("Classique");
		gameTypeComboBox->addItem("Contre la montre");
		gameTypeComboBox->addItem("Victoire en fonction du score");
		gameTypeComboBox->addItem("Victoire en fonction du nombre de lignes");
		gameTypeComboBox->setStyleSheet("background-color: #FFFFFF; color: #000000; border-radius: 10px; padding: 5px 10px;");
		gameTypeComboBox->setFixedWidth(250);
		layout->addWidget(gameTypeComboBox);
		gameTypeComboBox->hide();

		// Create the additional parameter input
		additionalParameterInput = new QLineEdit(this);
		additionalParameterInput->setPlaceholderText("Entrez le paramètre supplémentaire");
		additionalParameterInput->setStyleSheet("background-color: #FFFFFF; color: #000000; border-radius: 10px; padding: 5px 10px;");
		additionalParameterInput->setFixedWidth(250);
		layout->addWidget(additionalParameterInput);
		additionalParameterInput->hide();

		// Create the difficulty label
		difficultyLabel = new QLabel("Vitesse initiale", this);
		difficultyLabel->setStyleSheet("color: #FFFFFF;");
		layout->addWidget(difficultyLabel);
		difficultyLabel->hide();

		// Create the difficulty combo box
		difficultyComboBox = new QComboBox(this);
		difficultyComboBox->addItem("Normal");
		difficultyComboBox->addItem("Rapide");
		difficultyComboBox->addItem("Ça va vite!");
		difficultyComboBox->addItem("ALED!!!");
		difficultyComboBox->setStyleSheet("background-color: #FFFFFF; color: #000000;border-radius: 10px; padding: 5px 10px;");
		difficultyComboBox->setFixedWidth(250);
		layout->addWidget(difficultyComboBox);
		difficultyComboBox->hide();

		// Create the blocks check box

		blocksCheckBox = new QCheckBox("Activer les blocs spéciaux", this);
		blocksCheckBox->setStyleSheet("color: #FFFFFF;");
		layout->addWidget(blocksCheckBox);
		blocksCheckBox->hide();

		// Create the settings return button
		settingsReturnButton = new QPushButton("Retour", this);
		settingsReturnButton->setStyleSheet("background-color: #FFFFFF; color: #1c8dd9;  border-radius: 10px; padding: 5px; margin-top: 20px;");
		settingsReturnButton->setCursor(Qt::PointingHandCursor);
		layout->addWidget(settingsReturnButton);
		settingsReturnButton->hide();

		// Create the confirm button
		confirmButton = new QPushButton("Confirmer", this);
		confirmButton->setStyleSheet("background-color: #1c8dd9; color: #FFFFFF;  border-radius: 10px; padding: 5px");
		confirmButton->setCursor(Qt::PointingHandCursor);
		layout->addWidget(confirmButton);
		confirmButton->hide();

		// Connect the currentIndexChanged signal of the gameTypeComboBox to the updateAdditionalParameterInputDisplay slot
		connect(gameTypeComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this,&MenuScene::updateAdditionalParameterInputDisplay);

		// Connect the buttons
		connect(playButton, &QPushButton::clicked, this, &MenuScene::showGameSettings);
		//TODO QUIT BUTTON
		connect(settingsReturnButton, &QPushButton::clicked, this, &MenuScene::closeGameSettings);

	}

	MenuScene::~MenuScene() {
		delete layout;
		delete title;
		delete playButton;
		delete quitButton;
	}

	void MenuScene::showGameSettings() {
		quitButton->hide();
		playButton->hide();
		gameTypeLabel->show();
		gameTypeComboBox->show();
		difficultyLabel->show();
		difficultyComboBox->show();
		blocksCheckBox->show();
		settingsReturnButton->show();
		confirmButton->show();

	}

	void MenuScene::closeGameSettings() {
		quitButton->show();
		playButton->show();
		gameTypeLabel->hide();
		gameTypeComboBox->hide();
		difficultyLabel->hide();
		difficultyComboBox->hide();
		blocksCheckBox->hide();
		settingsReturnButton->hide();
		confirmButton->hide();
	}

	void MenuScene::updateAdditionalParameterInputDisplay(int index) {
		// If the selected game type is not "Classique", show the additional parameter input
		if (index == 1) {
			additionalParameterInput->setPlaceholderText("Entrez le temps à atteindre");
			additionalParameterInput->show();
		} else if (index == 2) {
			additionalParameterInput->setPlaceholderText("Entrez le score à atteindre");
			additionalParameterInput->show();
		} else if (index == 3) {
			additionalParameterInput->setPlaceholderText("Entrez le nombre de lignes à atteindre");
			additionalParameterInput->show();
		} else {
			additionalParameterInput->hide();
		}
	}

} // namespace tetris::view::gui