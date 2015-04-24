#ifndef DESKTOPTRANQUILIZER_H
#define DESKTOPTRANQUILIZER_H

#include "tranquilizer.h"

namespace Ilwis {
namespace Geodrawer {

class DesktopTranquilizer : public BaseTranquilizer
{
    Q_OBJECT
public:
    DesktopTranquilizer(const IOOptions& opt, QObject *parent);
    ~DesktopTranquilizer();

    void prepare(const QString &title, const QString &description, double end, double start=0);
    void update(double step);
    void stop();

    static Tranquilizer *create(const IOOptions &opt);
};
}
}

#endif // DESKTOPTRANQUILIZER_H
