#include "moddependenciesdelegate.h"
#include <QPainter>

ModDependenciesDelegate::ModDependenciesDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{
}

void ModDependenciesDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected)
                painter->fillRect(option.rect, option.palette.highlight());

    painter->drawText(option.rect, Qt::AlignVCenter|Qt::TextSingleLine, index.data().toStringList().join(", "));
}

QSize ModDependenciesDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStringList text = index.data().toStringList();
    return QSize(option.fontMetrics.width(text.join(", ")), option.fontMetrics.height());
}
