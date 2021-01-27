#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QItemSelection>
#include <QWidget>
#include "storage.h"

namespace Ui {
class ShopWindow;
}

class ShopWindow : public QWidget
{
    Q_OBJECT
public:
    explicit ShopWindow(QWidget *parent = nullptr);
    ~ShopWindow();

private slots:
    void on_catListView_activated(const QModelIndex &index);
    void on_addToCart_clicked();
    void on_addToCart_2_clicked();
    void on_addToCart_3_clicked();
    void on_addToCart_4_clicked();
    void on_addToCart_5_clicked();
    void on_addToCart_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::ShopWindow *ui;
    Storage *storage;
    Ship *selectedShip;
    std::list<int> shipsIndexes;
    std::list<std::string>::iterator it;
    void handleSelectionChanged(const QItemSelection &selection);
    void changeToShips();
    void changeToUpgrades();
    void changeToChests();
    void changeToDrinks();
    void changeToDrugs();
    void changeToSpecial();
    void savePlayerInventory(int index);
    void openPlayerInventory();
};

#endif // SHOPWINDOW_H
