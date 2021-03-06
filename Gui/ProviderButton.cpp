#include "ProviderButton.hpp"

QPushButton *ProviderButton::create(const Provider &provider)
{
    QPushButton *btn = new QPushButton(provider.name);
    btn->setObjectName(provider.id);
    btn->setGeometry(-1, -1, 80, 80);
    btn->setFixedWidth(95);
    btn->setFixedHeight(95);
    btn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
    btn->setFlat(true);
    btn->setFocusPolicy(Qt::TabFocus);
    btn->setStyleSheet(
        "QPushButton{outline: none; border: none; padding: 5px; color: #ffffff;}"
        "QPushButton:focus{outline: none; border: 1px solid #f3f3f3; padding: 5px;}"
        "QPushButton:hover{outline: none; border: 1px solid #ffffff; padding: 5px; background-color: #555555;}"
        "QPushButton:pressed{outline: none; border: 1px solid #ffffff; padding: 5px; background-color: #484848;}");

    if (!provider.icon.icon.isNull())
    {
        btn->setIcon(provider.icon.icon);
        btn->setIconSize(QSize(80, 80));
        btn->setText(QString());
        btn->setToolTip(provider.name);
    }

    return btn;
}

ProviderListModel::ProviderListModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

ProviderListModel::~ProviderListModel()
{
}

int ProviderListModel::rowCount(const QModelIndex &) const
{
    return StreamingProviderStore::instance()->count();
}

int ProviderListModel::columnCount(const QModelIndex &) const
{
    // col 1: icon
    // col 2: name
    return 2;
}

QVariant ProviderListModel::data(const QModelIndex &index, int role) const
{
    const auto row = index.row();
    const auto col = index.column();

    switch (role)
    {
        case Qt::DisplayRole:
            switch (col)
            {
                case 1: return StreamingProviderStore::instance()->providerAt(row).name;
            }
            break;
        case Qt::DecorationRole:
            switch (col)
            {
                case 0: return StreamingProviderStore::instance()->providerAt(row).icon.icon;
            }
            break;
    }
    return QVariant();
}
