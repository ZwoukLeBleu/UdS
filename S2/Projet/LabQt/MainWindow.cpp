#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    label = new QLabel("salut !");
	menu = new QMenuBar(this);
	textEdit = new QTextEdit(this);
    button = new QPushButton("Cliquez Ici");

	textEdit->setReadOnly(true);

	QMenu* fichier = menu->addMenu("Fichier");
    QAction* ouvrir = fichier->addAction("Ouvrir");
	QAction* fermer = fichier->addAction("Fermer");
	QMenu* edition = menu->addMenu("Edition");
	QAction* trouver = edition->addAction("Trouver");

    QWidget* centralWidget = new QWidget(this);
	QVBoxLayout* layout = new QVBoxLayout(centralWidget);

	layout->setMenuBar(menu);
    layout->addWidget(label);
	layout->addWidget(textEdit);
	layout->addWidget(button, 0, Qt::AlignRight);

    setCentralWidget(centralWidget);

	/*QObject::connect(button, &QPushButton::clicked, [this]() {
		textEdit->append("action: bouton");
		});

	QObject::connect(ouvrir, &QAction::triggered, [this]() {
		textEdit->append("action: fhcier/ouvrir");
		});
	QObject::connect(fermer, &QAction::triggered, [this]() {
		textEdit->append("action: fichier/fermer");
		});
	QObject::connect(trouver, &QAction::triggered, [this]() {
		textEdit->append("action: edition/trouver");
		});*/

	QObject::connect(button, &QPushButton::clicked, this, &MainWindow::buttonClicked);
	QObject::connect(ouvrir, &QAction::triggered, this, &MainWindow::ouvrirClicked);
	QObject::connect(fermer, &QAction::triggered, this, &MainWindow::fermerClicked);
	QObject::connect(trouver, &QAction::triggered, this, &MainWindow::trouverClicked);
}

MainWindow::~MainWindow() {
}

void MainWindow::buttonClicked() {
	textEdit->append("action: bouton");
}

void MainWindow::ouvrirClicked() {
	textEdit->append("action: fichier/ouvrir");
}

void MainWindow::fermerClicked() {
	textEdit->append("action: fichier/fermer");
}

void MainWindow::trouverClicked() {
	textEdit->append("action: edition/trouver");
}
