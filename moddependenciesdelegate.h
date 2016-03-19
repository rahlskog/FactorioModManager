#ifndef MODDEPENDENCIESDELEGATE_H
#define MODDEPENDENCIESDELEGATE_H
#include <QStyledItemDelegate>

class ModDependenciesDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ModDependenciesDelegate(QWidget *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const Q_DECL_OVERRIDE;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;

private slots:

};

#endif // MODDEPENDENCIESDELEGATE_H
