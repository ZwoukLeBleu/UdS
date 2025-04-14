#pragma once
#include <qmainwindow.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <QVBoxLayout>
#include <qmenubar.h>
#include <qgridlayout.h>
#include <qtextedit.h>


class MainWindow : public QMainWindow
{
	//Q_OBJECT
public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
private:
	QLabel* label;
	QPushButton* button;
	QMenuBar* menu;
	QTextEdit* textEdit;
public slots:
	void buttonClicked();
	void ouvrirClicked();
	void fermerClicked();
	void trouverClicked();
};
