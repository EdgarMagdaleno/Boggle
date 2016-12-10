#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QCloseEvent>
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
 	bool shouldClose();

protected:
    void closeEvent(QCloseEvent *event);
 
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
