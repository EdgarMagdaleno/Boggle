#ifndef WIDGET_H
#define WIDGET_H

#include "Boggle.h"
#include <string>
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QTimer>

namespace Ui{
class Widget;
}

class Widget : public QWidget{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
 	void setLine(const QString &str);
 	void updateBoard();
 	
private slots:
	void jugarClicked();
	void nuevoClicked();
	void rotarClicked();
	void resolverClicked();
	void lineEditReturn();
	void tiempoTerminado();

private:
    Ui::Widget *ui;
    QTimer *timer;
    Boggle *boggle;
    int points;
};

#endif // WIDGET_H
