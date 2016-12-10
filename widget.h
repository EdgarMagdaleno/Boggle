#ifndef WIDGET_H
#define WIDGET_H

#include "Boggle.h"
#include <QWidget>
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

namespace Ui{
class Widget;
}

class Widget : public QWidget{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
 	void setLine(const QString &str);
 	QString lineInput() const;
 	void showInput() const;

private slots:
	void jugarClicked();
	void nuevoClicked();
	void rotarClicked();
	void resolverClicked();
	
private:
    Ui::Widget *ui;
    Boggle *boggle;
};

#endif // WIDGET_H
