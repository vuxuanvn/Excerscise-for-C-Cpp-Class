#include "listusebook.h"
#include "ui_listusebook.h"

ListUseBook::ListUseBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListUseBook)
{
    ui->setupUi(this);
    model = new QSqlRelationalTableModel(this);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setTable("muonsach");

    // Remember the indexes of the columns:
    userID = model->fieldIndex("user_id");


    // Set the relations to the other database tables:
    model->setRelation(userID, QSqlRelation("account", "id", "username"));


    model->select();

    // Set the model and hide the ID column:
    ui->tableViewListUserUseBook->setModel(model);
}

ListUseBook::~ListUseBook()
{
    delete ui;
}
