#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    
    ui(new Ui::Widget){
    ui->setupUi(this);
}

Widget::~Widget(){
    delete ui;
}

void Widget::closeEvent(QCloseEvent *event){
	if (shouldClose())
		event->accept();
	else
		event->ignore();
}

bool Widget::shouldClose(){
    if(!isWindowModified())
		return true;

	QMessageBox::StandardButton ans = QMessageBox::question(this, tr("Cerrar juego"), tr("Tenemos un 10?"),QMessageBox::Yes | QMessageBox::No);

	return (ans == QMessageBox::Yes);
}

void Widget::setLine(const QString &str){
  ui->lineEdit->setText(str);
}
 
QString Widget::lineInput() const{
  return ui->lineEdit->text();
}

//Agregar evaluacion del input

void Widget::showInput() const{		//Agrega el input al label
  ui->label->setText(ui->label->text()+"\n"+ui->lineEdit->text());
}
