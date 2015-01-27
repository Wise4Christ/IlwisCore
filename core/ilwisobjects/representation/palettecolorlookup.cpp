#include "kernel.h"
#include "ilwisdata.h"
#include "range.h"
#include "itemrange.h"
#include "colorrange.h"
#include "numericrange.h"
#include "datadefinition.h"
#include "palettecolorlookup.h"

using namespace Ilwis;

PaletteColorLookUp::PaletteColorLookUp(const QString &definition){
    int index = 0;
    QStringList parts = definition.split("|");
    for( QString part : parts){
        if ( index == 0) {
            _cyclic = part == "true";
            ++index;
            continue;
        }
        QColor color = string2color(part);
        _colors[index - 1] = color;
    }
}

PaletteColorLookUp::PaletteColorLookUp(boost::container::flat_map<quint32, QColor> &newcolors) : _colors(newcolors)
{

}

QColor PaletteColorLookUp::value2color(double index, const NumericRange &rng, const NumericRange &) const
{
    int localIndex  = index;
    if ( _cyclic){
        localIndex = localIndex % rng.count();
    }
    auto iter = _colors.find(localIndex);
    if ( iter != _colors.end()){

        QColor clr =  (*iter).second;
        qDebug() << clr << index << localIndex;
        return clr;
    }
    return QColor();
}
