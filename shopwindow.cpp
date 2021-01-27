#include "shopwindow.h"
#include "ui_shopwindow.h"
#include <qstringlistmodel.h>
#include <string.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>

ShopWindow::ShopWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);
    QStringListModel *model = new QStringListModel(this);
    QStringList list;

    openPlayerInventory();

    storage = Storage::getInstance();
    list << "Ships";
    model->setStringList(list);
    ui->catListView->setModel(model);
    ui->catListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
   connect(ui->catListView->selectionModel(),
          SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
          this, SLOT(handleSelectionChanged(QItemSelection)));
    ui->catLabel->setText("Items");
    changeToShips();




    if (shipsIndexes.size()>0){
        for(auto &s: shipsIndexes){
            if (s == 1){
                ui->addToCart->setEnabled(false);
                ui->pushButton->setEnabled(true);
            }
            if (s == 2){
                ui->addToCart_2->setEnabled(false);
                ui->pushButton_2->setEnabled(true);
            }
            if (s == 3){
                ui->addToCart_3->setEnabled(false);
                ui->pushButton_3->setEnabled(true);
            }
            if (s == 4){
                ui->addToCart_4->setEnabled(false);
                ui->pushButton_4->setEnabled(true);
            }
            if (s == 5){
                ui->addToCart_5->setEnabled(false);
                ui->pushButton_5->setEnabled(true);
            }
            if (s == 6){
                ui->addToCart_6->setEnabled(false);
                ui->pushButton_6->setEnabled(true);
            }
        }
    }

}

ShopWindow::~ShopWindow()
{
    delete ui;
}

void ShopWindow::handleSelectionChanged(const QItemSelection& selection)
{
    if(!selection.indexes().isEmpty())
    {
      on_catListView_activated(selection.indexes().first());
    }
}

void ShopWindow::changeToShips()
{
    QLabel *itemLabels[6] {ui->item, ui->item_2, ui->item_3, ui->item_4, ui->item_5, ui->item_6};
    QLabel *priceLables[6] {ui->price, ui->price_2, ui->price_3, ui->price_4, ui->price_5, ui->price_6};
    QLabel *goodsPics[6] {ui->goods, ui->goods_2, ui->goods_3, ui->goods_4, ui->goods_5, ui->goods_6};

    QString items[6] {"Ship 1", "Ship 2", "Ship 3", "Ship 4", "Ship 5", "Ship 6"};
    QString prices[6] {"500", "1000", "1500", "2000", "2500", "3000"};
    QString goods[6] {"E:/SpaceShooter/SpaceShooter/Image/Ship/Ship/Ship (1).png", "E:/SpaceShooter/SpaceShooter/Image/Ship/Ship/Ship (2).png",
                      "E:/SpaceShooter/SpaceShooter/Image/Ship/Ship/Ship (3).png", "E:/SpaceShooter/SpaceShooter/Image/Ship/Ship/Ship (4).png",
                      "E:/SpaceShooter/SpaceShooter/Image/Ship/Ship/Ship (5).png", "E:/SpaceShooter/SpaceShooter/Image/Ship/Ship/Ship (6).png"};

    for (int i = 0; i < 6; ++i) {
        itemLabels[i]->setText(items[i]);
        priceLables[i]->setText(prices[i]);
        QPixmap pixmap(goods[i]);
        int w = goodsPics[i]->width();
        int h = goodsPics[i]->height();
        goodsPics[i]->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
        goodsPics[i]->show();
    }
}


void ShopWindow::savePlayerInventory(int index){

    QString filename = "E:/SpaceShooter/SpaceShooter/Inventory/playerInventory.txt";
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << index << endl;
    }

    file.close();
}
void ShopWindow::openPlayerInventory()
{
    QString filename = "E:/SpaceShooter/SpaceShooter/Inventory/playerInventory.txt";
    QFile file(filename);

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        while(!file.atEnd())
        {
            QString line = file.readLine();
            std::string index = line.toStdString();
            shipsIndexes.push_back(std::stoi(index));
        }

    }

    file.close();
}

void ShopWindow::on_catListView_activated(const QModelIndex &index)
{
    switch (index.row()) {
        case 0:
    {
            ui->catLabel->setText("Ships");
            changeToShips();
    }
        break;
    }
}

void ShopWindow::on_addToCart_clicked()
{
    ui->pushButton->setEnabled(true);
    if (ui->pushButton->isEnabled()){
        ui->addToCart->setEnabled(false);
    }
    savePlayerInventory(1);
}

void ShopWindow::on_addToCart_2_clicked()
{
    ui->pushButton_2->setEnabled(true);
    if (ui->pushButton_2->isEnabled()){
        ui->addToCart_2->setEnabled(false);
    }
    savePlayerInventory(2);
}

void ShopWindow::on_addToCart_3_clicked(){
    ui->pushButton_3->setEnabled(true);
    if (ui->pushButton_3->isEnabled()){
        ui->addToCart_3->setEnabled(false);
    }
    savePlayerInventory(3);
}

void ShopWindow::on_addToCart_4_clicked()
{
    ui->pushButton_4->setEnabled(true);
    if (ui->pushButton_4->isEnabled()){
        ui->addToCart_4->setEnabled(false);
    }
    savePlayerInventory(4);
}

void ShopWindow::on_addToCart_5_clicked()
{
    ui->pushButton_5->setEnabled(true);
    if (ui->pushButton_5->isEnabled()){
        ui->addToCart_5->setEnabled(false);
    }
    savePlayerInventory(5);
}

void ShopWindow::on_addToCart_6_clicked()
{
    ui->pushButton_6->setEnabled(true);
    if (ui->pushButton_6->isEnabled()){
        ui->addToCart_6->setEnabled(false);
    }
    savePlayerInventory(6);
}


void ShopWindow::on_pushButton_clicked()
{
    selectedShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (1).png",Red,3);
    storage->setSelectedShip(selectedShip);
}

void ShopWindow::on_pushButton_2_clicked()
{
    selectedShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (2).png",Green,3);
    storage->setSelectedShip(selectedShip);
}

void ShopWindow::on_pushButton_3_clicked()
{
    selectedShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (3).png",Yellow,3);
    storage->setSelectedShip(selectedShip);
}

void ShopWindow::on_pushButton_4_clicked()
{
    selectedShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (4).png",Blue,3);
    storage->setSelectedShip(selectedShip);
}

void ShopWindow::on_pushButton_5_clicked()
{
    selectedShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (5).png",RedUpgrade,3);
    storage->setSelectedShip(selectedShip);
}

void ShopWindow::on_pushButton_6_clicked()
{
    selectedShip = new Ship("E:/SpaceShooter/SpaceShooter/Image/Ship (6).png",YellowUpgrade,3);
    storage->setSelectedShip(selectedShip);
}
