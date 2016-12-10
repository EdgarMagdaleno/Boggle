#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    
    ui(new Ui::Widget){
    ui->setupUi(this);
    boggle = new Boggle();
    boggle->newGame();
	
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(jugarClicked()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(nuevoClicked()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(rotarClicked()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(resolverClicked()));
}

Widget::~Widget(){
    delete ui;
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

void Widget::jugarClicked(){
    ui->label->setText("");
    QString a = "";

	a.append(boggle->board[0][0]);
	ui->label_1->setText(a);
	a = "";
	a.append(boggle->board[0][1]);
	ui->label_2->setText(a);
	a = "";
	a.append(boggle->board[0][2]);
	ui->label_3->setText(a);
	a = "";
	a.append(boggle->board[0][3]);
	ui->label_4->setText(a);
	a = "";
	a.append(boggle->board[1][0]);
	ui->label_5->setText(a);
	a = "";
	a.append(boggle->board[1][1]);
	ui->label_6->setText(a);
	a = "";
	a.append(boggle->board[1][2]);
	ui->label_7->setText(a);
	a = "";
	a.append(boggle->board[1][3]);
	ui->label_8->setText(a);
	a = "";
	a.append(boggle->board[2][0]);
	ui->label_9->setText(a);
	a = "";
	a.append(boggle->board[2][1]);
	ui->label_10->setText(a);
	a = "";
	a.append(boggle->board[2][2]);
	ui->label_11->setText(a);
	a = "";
	a.append(boggle->board[2][3]);
	ui->label_12->setText(a);
	a = "";
	a.append(boggle->board[3][0]);
	ui->label_13->setText(a);
	a = "";
	a.append(boggle->board[3][1]);
	ui->label_14->setText(a);
	a = "";
	a.append(boggle->board[3][2]);
	ui->label_15->setText(a);
	a = "";
	a.append(boggle->board[3][3]);
	ui->label_16->setText(a);
}

void Widget::nuevoClicked(){
	boggle->newGame();
	jugarClicked();
}

void Widget::rotarClicked(){
	char nueva[4][4];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			nueva[i][j] = boggle->board[4-j-1][i];
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			boggle->board[i][j] = nueva[i][j];
		}
	}
	jugarClicked();
}

void Widget::resolverClicked(){
	ui->label->setText("");
	QString a = "";
	for(int i=0;boggle->words[i];i++){
		a = ui->label->text();
		a.append(boggle->words[i]);
		ui->label->setText(a);
	}
}