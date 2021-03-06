#ifndef PROVIDERBUTTON_HPP
#define PROVIDERBUTTON_HPP

#include <QAbstractTableModel>
#include <QPushButton>

#include <Core/StreamingProviderStore.hpp>

namespace ProviderButton
{
    QPushButton *create(const Provider &provider);
};

class ProviderListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ProviderListModel(QObject *parent = nullptr);
    ~ProviderListModel() override;

    inline void reload()
    {
        this->beginResetModel();
        // external data update
        this->endResetModel();
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
};

#endif // PROVIDERBUTTON_HPP
