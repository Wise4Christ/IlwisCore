#ifndef LAYERSVIEWCOMMANDINTERFACE
#define LAYERSVIEWCOMMANDINTERFACE

#include "ilwiscoreui_global.h"
#include <QVariantMap>

class ILWISCOREUISHARED_EXPORT LayersViewCommandInterface {
public:
    LayersViewCommandInterface();
    virtual ~LayersViewCommandInterface();
    virtual void addCommand(const QString& command, const QVariantMap& params) = 0;
};

#endif // LAYERSVIEWCOMMANDINTERFACE

